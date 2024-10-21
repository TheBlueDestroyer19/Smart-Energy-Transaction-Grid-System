#include "combined.h"
#include <stdio.h>

//Initializes entire array to 0
void initializeZero(struct SmartGridTransaction record[], int size) {
    for (int i = 0; i < size; i++) {
        record[i].transactionID=0;
        record[i].buyerID=0;
        record[i].sellerID=0;
        record[i].amountOfEnergy=0.0;
        record[i].priceKWh=0.0;
        record[i].date[0]='\0';
        record[i].time[0]='\0';
        record[i].flag=0;
    }    
}