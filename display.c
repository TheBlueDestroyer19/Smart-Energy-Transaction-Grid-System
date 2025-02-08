#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "template.h"

void displayData(TransNode *mainhead) {   
  TransNode* temp=mainhead;

  while(temp!=NULL) {
    printf("Transaction Id: %u\n",temp->entry.transID);
    printf("Seller Id: %d\n",temp->entry.sellerID);
    printf("Buyer Id: %d\n",temp->entry.buyerID);
    printf("Amount of energy in kWh: %f\n",temp->entry.amtOfEnergy);
    printf("Price per kWh: %f\n",temp->entry.pricePerKWh);
    printf("The date is %s\n",temp->entry.date);
    printf("The time of transaction is %s\n\n",temp->entry.time);
    temp=temp->next;
  }
}
