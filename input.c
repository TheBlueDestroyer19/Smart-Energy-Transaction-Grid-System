#include "combined.h"
#include <stdio.h>
#include <string.h>

int inputValues(struct SmartGridTransaction record[], int filled, int size) {
    int trans_ID, buyer_ID, seller_ID;
    float amt_energy, price;
    char date_tr[20], time_tr[20];
    //Variables for each attribute

    printf("How many entries do you want to make?\n\n"); int numEntries;
    scanf("%d",&numEntries);

    for(int i=1;i<=numEntries && filled<=size;i++) {
        printf("Entry Number %d\n",i);

        printf("Enter the transaction ID:  ");
        scanf("%d",&trans_ID);
        int flag=0;
        for(int j=0;j<filled;j++) {
            if(trans_ID==record[j].transactionID) flag=1;
        }

        //Checking if the transaction ID already exists
        if(flag==1) {printf("A transaction with this ID already exists. Enter a new one please.\n"); i=i-1;}
        else {
            printf("Enter the buyer ID:  ");
            scanf("%d",&buyer_ID);

            printf("Enter the seller ID:  ");
            scanf("%d",&seller_ID);

            printf("Enter the amount of energy consumed:  ");
            scanf("%f",&amt_energy);

            printf("Enter the price per KWh:  ");
            scanf("%f",&price);

            printf("Enter the date of transaction in the format \"DD:MM:YYYY\":  ");
            scanf("%s",date_tr);

            printf("Enter the time of transaction in the format \"HH:MM:SS\":  ");
            scanf("%s",time_tr);
            printf("\n\n");

            record[filled].transactionID=trans_ID;
            record[filled].sellerID=seller_ID;
            record[filled].buyerID=buyer_ID;
            record[filled].amountOfEnergy=amt_energy;
            record[filled].priceKWh=price;
            strcpy(record[filled].date,date_tr);
            strcpy(record[filled].time,time_tr);
            //Atlast adding the new entry to the structure array

            filled=filled+1;
            //Number of elements incremented by 1
        }
        flag=0;
        //Flag value reset
    }
    return filled;
    //The number of elements in the array are returned
}