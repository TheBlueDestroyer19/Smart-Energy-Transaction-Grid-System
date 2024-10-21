#include <stdio.h>
#include "combined.h"

void pairWithMaxTrans(struct SmartGridTransaction record[], int filled) {
    int buyer_ID, seller_ID;
    
    int count=1,maxcnt=1, maxtimebID,maxtimesID;
    //To count and check which buyer-seller pair appears for the maximum number of times
    for(int i=0;i<filled-1;i++) {
        buyer_ID=record[i].buyerID;
        seller_ID=record[i].sellerID;

        for(int j=i+1;j<filled;j++) {
            if(buyer_ID==record[j].buyerID && seller_ID==record[j].sellerID)
                count++;
            //Increment if the buyer-seller pairs are encountered ahead
        }
        if(maxcnt<count) {
            maxcnt=count;
            maxtimebID=buyer_ID;
            maxtimesID=seller_ID;
        }
        //Maxcheck

        count=1;
        //count reinitialized to 1
    }
    printf("The buyer-seller pair which occurs for the maximum number of times is:\n");
    printf("Buyer ID: %d\tSeller ID: %d\n\n",maxtimebID,maxtimesID);
}