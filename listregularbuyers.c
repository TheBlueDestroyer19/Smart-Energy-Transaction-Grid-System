#include <stdio.h>
#include <stdlib.h>
#include "template.h"

void createListRegular(SellersList *sellerhead, Pair *pairhead) {
  Pair* ptr=pairhead;
  SellersList *sptr;
  IdNode* nptr;
  int found;
  if(ptr==NULL) printf("Create the list of buyer-seller pairs first!!\n");
  while(ptr!=NULL && ptr->count>=5) {
    sptr=sellerhead;
    found=0;
    while(sptr!=NULL && !found) {
      if(ptr->sellerID==sptr->attributes.sellerID) {
        found=1;
        if(ptr->flag==0) {
          ptr->flag=1;
          nptr=(IdNode*)malloc(sizeof(IdNode));
          nptr->id=ptr->buyerID;
          nptr->next=NULL;
          if(sptr->attributes.regularBuyersHead==NULL) sptr->attributes.regularBuyersHead=nptr;
          else (sptr->attributes.regularBuyersTail)->next=nptr;
          sptr->attributes.regularBuyersTail=nptr;
        }
      }
      sptr=sptr->next;
    }
    ptr=ptr->next;
  }

  if(pairhead!=NULL) {
    printf("The list of regular buyers for different sellers:\n");
    sptr=sellerhead;
    while(sptr!=NULL) {
      printf("\nSeller ID: %u\n",sptr->attributes.sellerID);
      nptr=sptr->attributes.regularBuyersHead;
      if(nptr==NULL) printf("No regular buyer");
      while(nptr!=NULL) {
        printf("%d, ",nptr->id);
        nptr=nptr->next;
      }
      printf("\n");
      sptr=sptr->next;
    }
  }
}
