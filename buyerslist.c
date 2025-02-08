#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "template.h"

void showBuyersList(seller_buyer* buyerlisthead) {
  TransNode *temp; int p=0;
  while(buyerlisthead!=NULL) {
    printf("\n\nBuyer ID: %d\n",buyerlisthead->id);
    temp=buyerlisthead->memberhead;
    p=0;
    while(temp!=NULL) {
      printf("Transaction %d\n",(p+1));
      printf("Transaction ID: %d\n",temp->entry.transID);
      printf("Seller ID: %d\n",temp->entry.sellerID);
      printf("Amount of Energy: %f\n",temp->entry.amtOfEnergy);
      printf("Price per KWh: %f\n",temp->entry.pricePerKWh);
      printf("Date of transaction: %s\n",temp->entry.date);
      printf("Time of transaction: %s\n\n",temp->entry.time);
      temp=temp->next;
      p++;
    }
    printf("\n");
    buyerlisthead=buyerlisthead->next;
  }
}

retstat createBuyersList(seller_buyer** buyerlisthead,TransNode* mainhead) {
  retstat status_code=success;
  unsigned int id;
  TransNode *nptr, *temp;
  seller_buyer* newnode,* temp2;
  int present,redundant=0;

  while(mainhead!=NULL) {
    id=mainhead->entry.buyerID;
    //Check for existance in the sellerlist 
    present=0;
    temp2=*buyerlisthead;
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
      else *buyerlisthead=newnode;
      newnode->id=id;
      nptr=createTransNode(&(mainhead->entry));
      newnode->memberhead=nptr;
    }
    mainhead=mainhead->next;
  }
  showBuyersList(*buyerlisthead);
  return status_code;
}

