#include <stdio.h>
#include "combined.h"

void createAmtList(struct seller_buyer buyerlst[], float energyBought[], int lstbuyerfilled) {
    float amount;
    int j;
    for(int i=0;i<lstbuyerfilled;i++) {
        amount=0; j=0;
        while(buyerlst[i].trans[j].transactionID!=0) {
            amount=amount+buyerlst[i].trans[j].amountOfEnergy;
            j++;
        }
        energyBought[i]=amount;
    }
}


void sortBuyerList(struct seller_buyer buyerlst[], float energyBought[], int lstbuyerfilled) {
    
    createAmtList(buyerlst,energyBought,lstbuyerfilled);
    
    quickSort2(buyerlst,lstbuyerfilled-1,0,energyBought);

    printf("The list of buyers after sorting:\n");
    for(int i=0;i<lstbuyerfilled;i++) {
        printf("Buyer ID: %d\n",buyerlst[i].ID);
        printf("Total amount of energy bought: %f\n\n",energyBought[i]);
    }
}