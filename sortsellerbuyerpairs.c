#include "template.h"
#include<stdlib.h>
#include<stdio.h>
Pair* MergeSort2(Pair* lptr);
Pair* Merge2(Pair* list1, Pair* list2);
Pair* Divide2(Pair* lptr);

Pair* Merge2(Pair* list1, Pair* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    Pair* result = NULL;
    Pair* tail = NULL;

    Pair* ptr1 = list1;
    Pair* ptr2 = list2;

    if (ptr1->count > ptr2->count) {
        result = tail = ptr1;
        ptr1 = ptr1->next;
    } else {
        result = tail = ptr2;
        ptr2 = ptr2->next;
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->count > ptr2->count) {
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

Pair* Divide2(Pair* lptr) {
    if (lptr == NULL || lptr->next == NULL) {
        return NULL;
    }

    Pair* slow = lptr;
    Pair* fast = lptr->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Pair* nptr = slow->next;
    slow->next = NULL;
    return nptr;
}

Pair* MergeSort2(Pair* lptr) {
    if (lptr == NULL || lptr->next == NULL) {
        return lptr;
    }

    Pair* nptr = Divide2(lptr);
    lptr = MergeSort2(lptr);
    nptr = MergeSort2(nptr);
    return Merge2(lptr, nptr);
}
void sort_pairs(TransNode* mainhead)
{
    
    TransNode* temp=mainhead;
    if(temp!=NULL)
    {
    Pair* pairs=(Pair*)malloc(sizeof(Pair));
    Pair* pairhead=pairs;
    pairs->next=NULL;
    
    while(temp!=NULL)
    {   
        if(temp->entry.flag!=1)
        {
         pairs->count=1;
         pairs->buyerID=temp->entry.buyerID;
         pairs->sellerID=temp->entry.sellerID;
        if(temp->next!=NULL)
        {
        TransNode* temp2=temp->next;
        while(temp2!=NULL)
        {
            if(pairs->buyerID==temp2->entry.buyerID && pairs->sellerID==temp2->entry.sellerID)
            {
                pairs->count+=1;
                temp2->entry.flag=1;
            
            }
            temp2=temp2->next;
        }
        }
        }
        temp=temp->next;
        
        if(temp!=NULL&&temp->entry.flag!=1)
        {Pair* ptr=(Pair*)malloc(sizeof(Pair));
            pairs->next=ptr;
            pairs=ptr;
            pairs->next=NULL;
        }
        }
    
    pairhead=MergeSort2(pairhead);
    printf("Seller/Buyer pairs in decreasing order of the number of transactions between them are \n");
    pairs=pairhead;
    while(pairs!=NULL)
    {   
        printf("Seller ID:%d\n",pairs->sellerID);
        printf("Buyer ID:%d\n",pairs->buyerID);
        
        printf("Count:%d\n\n",pairs->count);
        pairs=pairs->next;
    }
    
    printf("Cleaning up the trash...done\n");
    while(pairhead!=NULL)
    {   Pair* ptr=pairhead;
        pairhead=pairhead->next;
        free(ptr);
    }
    }
}
