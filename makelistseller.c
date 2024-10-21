#include "combined.h"
#include <stdio.h>

int createListSeller(struct SmartGridTransaction record[], int filled, struct seller_buyer sellerlst[],  int lstsellerfilled) {
    int id, flag=0, p, flag2=0;
    for(int i=0;i<filled;i++) {
        id=record[i].sellerID;
        for(int k=0;k<lstsellerfilled;k++) {
            if(id==sellerlst[k].ID) {flag=1; p=k;}
        }
        //Checking if the sellerID exists in the array
        if(flag==1) {
            int x=0; flag2=0;
            while(sellerlst[p].trans[x].transactionID!=0) {
                if(sellerlst[p].trans[x].transactionID==record[i].transactionID) flag2=1;
                x++;
            }
            if(flag2==0) {
                sellerlst[p].trans[x]=record[i];
            }
        }
        //Appending the array if found
        else {
            initializeZero(sellerlst[lstsellerfilled].trans,SIZE);
            sellerlst[lstsellerfilled].ID=id;
            p=0;
            for(int j=i;j<filled;j++) {                
                if(id==record[j].sellerID) {                    
                    sellerlst[lstsellerfilled].trans[p]=record[j];
                    p++;
                }
            }
            lstsellerfilled++;
        }
        //If it does not exist only then a new entry is added to sellerlst

        flag=0;
        //Flag is reset
    }
    for(int i=0;i<lstsellerfilled;i++) {
        printf("\n\n\nSeller ID: %d\n\n",sellerlst[i].ID);
        p=0;
        while(sellerlst[i].trans[p].transactionID!=0) {
            printf("Transaction %d\n",(p+1));
            printf("Transaction ID: %d\n",sellerlst[i].trans[p].transactionID);
            printf("Buyer ID: %d\n",sellerlst[i].trans[p].buyerID);
            printf("Amount of Energy: %f\n",sellerlst[i].trans[p].amountOfEnergy);
            printf("Price per KWh: %f\n",sellerlst[i].trans[p].priceKWh);
            printf("Date of transaction: %s\n",sellerlst[i].trans[p].date);
            printf("Time of transaction: %s\n\n",sellerlst[i].trans[p].time);
            p++;
        }
        printf("\n");
    }
    return lstsellerfilled;
}