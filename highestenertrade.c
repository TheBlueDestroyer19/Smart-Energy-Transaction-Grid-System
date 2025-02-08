#include<stdio.h>
#include "template.h"
#include <stdio.h>
#include <stdlib.h>


TransNode* Merge(TransNode* list1, TransNode* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    TransNode* result = NULL;
    TransNode* tail = NULL;

    TransNode* ptr1 = list1;
    TransNode* ptr2 = list2;

    if (ptr1->entry.amtOfEnergy < ptr2->entry.amtOfEnergy) {
        result = tail = ptr1;
        ptr1 = ptr1->next;
    } else {
        result = tail = ptr2;
        ptr2 = ptr2->next;
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->entry.amtOfEnergy < ptr2->entry.amtOfEnergy) {
            tail->next = ptr1;
            ptr1 = ptr1->next;
        } else {
            tail->next = ptr2;
            ptr2 = ptr2->next;
        }
        tail = tail->next;
    }

    if (ptr1 != NULL) {
        tail->next = ptr1;
    } else {
        tail->next = ptr2;
    }

    return result;
}

TransNode* Divide(TransNode* lptr) {
    if (lptr == NULL || lptr->next == NULL) {
        return NULL;
    }

    TransNode* slow = lptr;
    TransNode* fast = lptr->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    TransNode* nptr = slow->next;
    slow->next = NULL;
    return nptr;
}

TransNode* MergeSort(TransNode* lptr) {
    if (lptr == NULL || lptr->next == NULL) {
        return lptr;
    }

    TransNode* nptr = Divide(lptr);
    lptr = MergeSort(lptr);
    nptr = MergeSort(nptr);
    return Merge(lptr, nptr);
}
TransNode* max_ener(TransNode *mainhead)
{
  TransNode* temp;
  temp=mainhead;
  temp=MergeSort(temp);
  mainhead=temp;
  displayData(mainhead);
    
  temp=mainhead;
  while(temp->next!=NULL) temp=temp->next;

  printf("The transaction with highest amount of energy traded is\n");
  printf("Transaction Id: %u\n",temp->entry.transID);
  printf("Buyer Id: %d\n",temp->entry.buyerID);
  printf("Seller Id: %d\n",temp->entry.sellerID);
  printf("Amount of energy in kWh: %f\n",temp->entry.amtOfEnergy);
  printf("Price per kWh: %f\n",temp->entry.pricePerKWh);
  printf("The date is %s\n",temp->entry.date);
  printf("The time of transaction is %s\n\n",temp->entry.time);
    
  return mainhead;
}
