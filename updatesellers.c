#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "template.h"

void updateSellers(SellersList **sellerhead) {
  unsigned int id;
  int found=0;
  SellersList *sptr=*sellerhead,*nptr;
  float price;
  printf("Enter the seller ID you want to add/update: "); scanf("%u",&id);

  while(sptr!=NULL && sptr->next!=NULL && !found) {
    if(sptr->attributes.sellerID==id) found=1;
    else sptr=sptr->next;
  }
  if(sptr->attributes.sellerID==id) found=1;

  if(found) {
    printf("Seller ID: %u\n",id);
    printf("Original price below 300: %f\n",sptr->attributes.b300);
    printf("Enter the new price below 300: ");
    scanf("%f",&price);
    sptr->attributes.b300=price;
    printf("Original price above 300: %f\n",sptr->attributes.a300);
    printf("Enter the new price above 300: ");
    scanf("%f",&price);
    sptr->attributes.a300=price;
  }
  else {
    printf("Seller ID: %u\n",id);
    nptr=(SellersList*)malloc(sizeof(SellersList));
    nptr->attributes.sellerID=id;
    printf("Enter the price below 300: ");
    scanf("%f",&price);
    nptr->attributes.b300=price;
    printf("Enter the price above 300: ");
    scanf("%f",&price);
    nptr->attributes.a300=price;
    if(sptr==NULL) *sellerhead=nptr;
    else sptr->next=nptr;
    nptr->next=NULL;
    nptr->attributes.regularBuyersHead=NULL;
    nptr->attributes.regularBuyersTail=NULL;
  }
}

void saveSellers(SellersList* sellerhead) {
  FILE* file = fopen("sellers.txt", "w");
  if(file==NULL) printf("Cannot open file\n");
  else {
    printf("File opened\n");
  SellersList* temp = sellerhead;
  while (temp!=NULL) {
    fprintf(file, "%u,%.2f,%.2f\n", temp->attributes.sellerID, temp->attributes.b300, temp->attributes.a300);
    temp = temp->next;
  }

  fclose(file);
  }
}

