#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "template.h"

seller_buyer* divideList(seller_buyer *buyerlisthead) {
  seller_buyer *fast,*slow,*temp=NULL;
  fast=slow=buyerlisthead;
  if(buyerlisthead==NULL || buyerlisthead->next==NULL) temp=NULL;
  else {
    fast=slow->next;
    while(fast!=NULL && fast->next!=NULL) {
      fast=fast->next->next;
      if(slow!=NULL) slow=slow->next;
    }
    temp=slow->next;
    slow->next=NULL;
  }
  return temp;
}
seller_buyer* mergeList(seller_buyer* first, seller_buyer* second) {
  seller_buyer *retval=NULL, *ptr1=first, *ptr2=second, *tail=NULL;
  if(first==NULL) retval=second;
  else if(second==NULL) retval=first;
  else {
    if(ptr1->totalenergy<ptr2->totalenergy) {
      retval=tail=ptr1;
      ptr1=ptr1->next;
    }
    else {
      retval=tail=ptr2;
      ptr2=ptr2->next;
    }
    while(ptr1!=NULL && ptr2!=NULL) {
      if(ptr1->totalenergy<ptr2->totalenergy) {
        tail->next=ptr1;
        ptr1=ptr1->next;
      }
      else {
        tail->next=ptr2;
        ptr2=ptr2->next;
      }
      tail=tail->next;
    }
    if(ptr1!=NULL) tail->next=ptr1;
    else tail->next=ptr2;
  }
  return retval;
}
seller_buyer* sortListBuyers(seller_buyer *buyerlisthead) {
  seller_buyer* retval,*second;
  if(buyerlisthead==NULL || buyerlisthead->next==NULL) retval=buyerlisthead;
  else {
    second=divideList(buyerlisthead);
    buyerlisthead=sortListBuyers(buyerlisthead);
    second=sortListBuyers(second);

    retval=mergeList(buyerlisthead,second);
  }
  return retval;
}

seller_buyer* calculateEnergy(seller_buyer *buyerlisthead) {
  seller_buyer* temp=buyerlisthead;
  TransNode* temp2;
  int energy=0;

  if(temp==NULL) printf("Please create the list of buyers first\n");

  while(temp!=NULL) {
    temp2=temp->memberhead;
    while(temp2!=NULL) {
      energy=energy+temp2->entry.amtOfEnergy;
      temp2=temp2->next;
    }
    temp->totalenergy=energy;
    energy=0;
    temp=temp->next;
  }

  if(buyerlisthead!=NULL) {
    buyerlisthead=sortListBuyers(buyerlisthead);
    temp=buyerlisthead;
    while(temp!=NULL) {
      printf("\nBuyer ID: %u\n",temp->id);
      printf("Energy Bought: %f\n",temp->totalenergy);
      temp=temp->next;
    }
  }
  return buyerlisthead;
}
