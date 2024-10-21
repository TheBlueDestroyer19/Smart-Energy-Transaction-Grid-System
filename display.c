#include<stdio.h>
#include "combined.h"
void displayData(struct SmartGridTransaction transaction[], int filled)
{   int i=0;
    while(i<filled)
    {
        printf("Transaction Id: %d\n",transaction[i].transactionID);
        printf("Buyer Id: %d\n",transaction[i].buyerID);
        printf("Seller Id: %d\n",transaction[i].sellerID);
        printf("Amount of energy in kWh: %f\n",transaction[i].amountOfEnergy);
        printf("Price per kWh: %f\n",transaction[i].priceKWh);
        printf("The date is %s\n",transaction[i].date);
        printf("The time of transaction is %s\n\n",transaction[i].time);
        i++;
    }
}