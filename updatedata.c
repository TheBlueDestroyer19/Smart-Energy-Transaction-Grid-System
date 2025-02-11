#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "template.h"

void update(TransNode* mainhead, SellersList* sellerhead) {
  printf("Enter the transaction ID to update\n");
  int id;
  scanf("%d",&id);
  TransNode* temp=mainhead;
  SellersList* sptr=sellerhead;
  int flag=0;

  while(temp!=NULL&&flag==0) {
    if(temp->entry.transID==id) flag=1;
    else temp=temp->next;        
  }

  if(flag==1) {
    printf("Enter the new amount of energy\n");
    float amt;
    scanf("%f",&amt);
    temp->entry.amtOfEnergy=amt;
    flag=0;
    while(sptr!=NULL && !flag) {
      if(sptr->attributes.sellerID == id) {
        flag=1;
        if(temp->entry.amtOfEnergy>=300) temp->entry.pricePerKWh=sptr->attributes.a300;
        else temp->entry.pricePerKWh=sptr->attributes.b300;
      }
      else sptr=sptr->next;
    }
  }
  else printf("No such transaction exists with the given Transaction ID\n");
}
