#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "template.h"

TransNode* createTransNode(SmartGridTransaction *data) {
  TransNode* nptr=(TransNode*)malloc(sizeof(TransNode));
  nptr->next=NULL;
  nptr->entry=*data;
  return nptr;
}

void showSellersList(seller_buyer* sellerlisthead) {
  TransNode *temp; int p=0;
  while(sellerlisthead!=NULL) {
    printf("\n\nSeller ID: %d\n",sellerlisthead->id);
    temp=sellerlisthead->memberhead;
    p=0;
    while(temp!=NULL) {
      printf("Transaction %d\n",(p+1));
      printf("Transaction ID: %d\n",temp->entry.transID);
      printf("Buyer ID: %d\n",temp->entry.buyerID);
      printf("Amount of Energy: %f\n",temp->entry.amtOfEnergy);
      printf("Price per KWh: %f\n",temp->entry.pricePerKWh);
      printf("Date of transaction: %s\n",temp->entry.date);
      printf("Time of transaction: %s\n\n",temp->entry.time);
      temp=temp->next;
      p++;
    }
    printf("\n");
    sellerlisthead=sellerlisthead->next;
  }
}

retstat createSellersList(seller_buyer** sellerlisthead,TransNode* mainhead) {
  retstat status_code=success;
  unsigned int id;
  TransNode *nptr, *temp;
  seller_buyer* newnode,* temp2;
  int present,redundant=0;

  while(mainhead!=NULL) {
    id=mainhead->entry.sellerID;
    //Check for existance in the sellerlist 
    present=0;
    temp2=*sellerlisthead;
    while(temp2!=NULL && temp2->next!=NULL && !present) {
      if(id==temp2->id) present=1;
      else temp2=temp2->next;
    }
    if(temp2!=NULL && id==temp2->id) present=1;

    if(present) {
      redundant=0;
      temp=temp2->memberhead;
      id=mainhead->entry.transID;
      while(temp->next!=NULL && !redundant) {
        if(temp->entry.transID==id) redundant=1;
        else temp=temp->next;
      }
      if(temp->entry.transID==id) redundant=1;
      if(!redundant) {
        nptr=createTransNode(&(mainhead->entry));
        temp->next=nptr;
      }
    }
    else {
      newnode=(seller_buyer*)malloc(sizeof(seller_buyer));
      newnode->next=NULL;
      if(temp2!=NULL) temp2->next=newnode;
      else *sellerlisthead=newnode;
      newnode->id=id;
      nptr=createTransNode(&(mainhead->entry));
      newnode->memberhead=nptr;
    }
    mainhead=mainhead->next;
  }
  showSellersList(*sellerlisthead);
  return status_code;
}
