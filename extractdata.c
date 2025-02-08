#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "template.h"

TransNode* createNode(SmartGridTransaction data) {
  TransNode* newNode = (TransNode*)malloc(sizeof(TransNode));
  int found=0;
  if (!newNode) {
    printf("Memory allocation failed!\n");
  }
  else {
    newNode->entry = data;
    if(found) newNode->next = NULL;
  }
  return newNode;
}

void insertAtEnd(TransNode** head, TransNode** tail, SmartGridTransaction data) {
  TransNode* newNode = createNode(data);
  if(newNode!=NULL) {
    if (*tail == NULL) *head = *tail = newNode;
    else {
      (*tail)->next = newNode;
      *tail = newNode;
    }
  }
}

void readTransactions(TransNode** head, TransNode** tail) {
  FILE* file = fopen("transactions.txt", "r");
  if (!file) {
    printf("Error opening file!\n");
    exit(1);
  }
    
  SmartGridTransaction temp;
  while (fscanf(file, "%u,%u,%u,%f,%f,%10[^,],%5s", 
                  &temp.transID, &temp.sellerID, &temp.buyerID, 
                  &temp.amtOfEnergy,&temp.pricePerKWh,temp.date, temp.time) == 7) {
    insertAtEnd(head, tail, temp);
  }
    
  fclose(file);
}
