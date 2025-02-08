#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "template.h"

void removeTransNode(TransNode **head) {
  if (*head != NULL) {
    TransNode *temp = *head;
    *head = temp->next;
    free(temp);
  }
}

void cleanTransList(TransNode **head) {
  printf("Cleaning the list.....");
  while (*head != NULL) {
    removeTransNode(head);
  }
  printf("Done\n");
}

void removeSellersNode(SellersList **head) {
  SellersList *temp=*head;
  if(temp!=NULL) {
    *head=temp->next;
    free(temp);
  }
}

void cleanSellersList(SellersList **head) {
  printf("Cleaning the list.....");
  while(*head!=NULL) removeSellersNode(head);
  printf("Done\n");
  *head=NULL;
}

void clearSellerListNode(seller_buyer** sellerlisthead) {
  seller_buyer* temp=*sellerlisthead;
  TransNode **temp2;
  if(temp!=NULL) {
    temp2=&(temp->memberhead);
    while(*temp2!=NULL) removeTransNode(temp2);
    (*sellerlisthead)=temp->next;
    free(temp);
  }
}
void clearSellersList(seller_buyer** sellerlisthead) {
  printf("Cleaning List.....");
  while(*sellerlisthead!=NULL) {
    clearSellerListNode(sellerlisthead);
  }
  printf("Done\n");
}
