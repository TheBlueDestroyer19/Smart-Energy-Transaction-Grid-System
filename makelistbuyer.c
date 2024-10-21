#include "combined.h"
#include <stdio.h>

//List of buyers created in the same way as the list of sellers
int createListBuyer(struct SmartGridTransaction record[], int filled, struct seller_buyer buyerlst[],  int lstbuyerfilled) {
    int id, flag=0, p,flag2;
    for(int i=0;i<filled;i++) {
        id=record[i].buyerID;
        for(int k=0;k<lstbuyerfilled;k++) {
            if(id==buyerlst[k].ID) {flag=1; p=k;}
        }
        //Checking if the sellerID exists in the array
        if(flag==1) {
            int x=0; flag2=0;
            while(buyerlst[p].trans[x].transactionID!=0) {
                if(buyerlst[p].trans[x].transactionID==record[i].transactionID) flag2=1;
                x++;
            }
            if(flag2==0) {
                buyerlst[p].trans[x]=record[i];
            }
        }
        //Appending the array if found
        else {
            initializeZero(buyerlst[lstbuyerfilled].trans,SIZE);
            buyerlst[lstbuyerfilled].ID=id;
            p=0;
            for(int j=i;j<filled;j++) {                
                if(id==record[j].buyerID) {                    
                    buyerlst[lstbuyerfilled].trans[p]=record[j];
                    p++;
                }
            }
            lstbuyerfilled++;
        }
        //Creating a new entry only if not found
        flag=0;
        //Resetting flag
    }
    for(int i=0;i<lstbuyerfilled;i++) {
        printf("\n\n\nBuyer ID: %d\n\n",buyerlst[i].ID);
        p=0;
        while(buyerlst[i].trans[p].transactionID!=0) {
            printf("Transaction %d\n",(p+1));
            printf("Transaction ID: %d\n",buyerlst[i].trans[p].transactionID);
            printf("Seller ID: %d\n",buyerlst[i].trans[p].sellerID);
            printf("Amount of Energy: %f\n",buyerlst[i].trans[p].amountOfEnergy);
            printf("Price per KWh: %f\n",buyerlst[i].trans[p].priceKWh);
            printf("Date of transaction: %s\n",buyerlst[i].trans[p].date);
            printf("Time of transaction: %s\n\n",buyerlst[i].trans[p].time);
            p++;
        }
        printf("\n");
    }
    return lstbuyerfilled;
}