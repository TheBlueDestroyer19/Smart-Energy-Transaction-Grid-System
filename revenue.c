#include "combined.h"
#include <stdio.h>

void totalRevenue(struct seller_buyer sellerlst[], float revenueGen[], int lstsellerfilled) {
    float sum; int j;
    
    for(int i=0;i<lstsellerfilled;i++) {
        sum=0; j=0;
        while(sellerlst[i].trans[j].transactionID!=0) {
            sum=sum+(sellerlst[i].trans[j].amountOfEnergy*sellerlst[i].trans[j].priceKWh);
            j++;
        }
        revenueGen[i]=sum;
    }

    printf("How many sellers' revenue do you want see?\n");
    int numOfSellers; scanf("%d",&numOfSellers);
    int found=0;
    for(int i=1;i<=numOfSellers;i++) {
        printf("Enter the seller ID: "); int sID; scanf("%d",&sID);
        for(int j=0;j<lstsellerfilled;j++) {
            if(sellerlst[j].ID==sID) {
                printf("Total Revenue generated by %d is %f\n\n",sID,revenueGen[j]);
                found=1;
            }
        } 
        if(found==0) printf("Seller ID not found\n\n");
        found=0;
    }
}