#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "template.h"

void revenueGenerated(seller_buyer *sellerlisthead) {
  seller_buyer* temp=sellerlisthead;
  float revenueSum=0;
  TransNode* temp2;
  unsigned int sid;
  int ch=1;
  
  if(temp==NULL) 
    printf("Please create a list of sellers first!!!\n");
  while(temp!=NULL) {
    temp2=temp->memberhead;
    while(temp2!=NULL) {
      revenueSum=revenueSum+(temp2->entry.amtOfEnergy)*(temp2->entry.pricePerKWh);
      temp2=temp2->next;
    }
    temp->revenue=revenueSum;
    revenueSum=0;
    temp=temp->next;
  }
  while(ch && sellerlisthead!=NULL) {
    printf("Enter the seller ID of whom the revenue should be generated:\n");
    scanf("%u",&sid);
    ch=0;
    temp=sellerlisthead;
    while(temp!=NULL && !ch) {
      if(sid==temp->id) {
        ch=1;
        printf("\nSeller ID: %d\n",temp->id);
        printf("Total Revenue Generated: %f\n",temp->revenue);
      }
      else temp=temp->next;
    }
    printf("Do you want to continue? (1/0): ");
    scanf("%d",&ch);
  }
}
