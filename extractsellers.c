#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "template.h"

void insertSeller(SellersList** head,SellersList **tail, unsigned int sellerID, float b300, float a300) {
  SellersList* newNode = (SellersList*)malloc(sizeof(SellersList));
  if (!newNode) {
    printf("Memory allocation failed!\n");
    return;
  }
  newNode->attributes.sellerID = sellerID;
  newNode->attributes.b300 = b300;
  newNode->attributes.a300 = a300;
  newNode->attributes.regularBuyers = NULL; 
  newNode->next = NULL;
  if(*tail!=NULL) (*tail)->next=newNode;
  else *head = newNode;
  *tail=newNode;
}

void loadSellersFromFile(SellersList** head, SellersList** tail) {
  FILE* file = fopen("sellers.txt", "r");
  if (!file) {
    printf("Error opening file!\n");
    return;
  }
    
  unsigned int sellerID;
  float b300, a300;
  while (fscanf(file, "%u,%f,%f", &sellerID, &b300, &a300) == 3) insertSeller(head, tail, sellerID, b300, a300);
  fclose(file);
}
