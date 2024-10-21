#include <stdio.h>
#include "combined.h"


int partition3(struct pair record[], int high, int low) {
    float x=record[low].revenue;
    int i=low, j=high;

    while(i<j && record[i].revenue>=x) i++;
    while(i<j && record[j].revenue<x) j--;
    if(record[i].revenue>x) j--;

    while(i<j) {
        swap3(&record[i],&record[j]);
        while(i<j && record[i].revenue>=x) i++;
        while(i<j && record[j].revenue<x) j--;
    }

    return j;
}

void quickSort3(struct pair record[], int high, int low) {
    int p=partition3(record,high,low);
    swap3(&record[low],&record[p]);
    quickSort3(record,p-1,low);
    quickSort3(record,high,p+1);
}

void sort_rev(struct SmartGridTransaction transaction[],int filled)
{
    struct pair pairs[SIZE];
    struct pair temp;
    int k=0;
    for(int i=0;i<filled;i++)
    {   
        if(transaction[i].flag!=1)
        {
         pairs[k].buyerID=transaction[i].buyerID;
         pairs[k].sellerID=transaction[i].sellerID;
         pairs[k].revenue=transaction[i].amountOfEnergy*transaction[i].priceKWh;
        for(int j=i+1;j<filled;j++)
        {
            if(pairs[k].buyerID==transaction[j].buyerID && pairs[k].sellerID==transaction[j].sellerID)
            {
                pairs[k].revenue+=transaction[j].amountOfEnergy*transaction[j].priceKWh;
                transaction[j].flag=1;
            
            }
        }
        k++;
        }
    }
    quickSort3(pairs,k-1,0);
    printf("seller/buyer pairs in decreasing order of the total revenue exchanged between them are \n");
for(int i=0;i<k;i++)
{
    printf("Buyer ID:%d\n",pairs[i].buyerID);
    printf("Seller ID:%d\n",pairs[i].sellerID);
    printf("revenue:%f\n\n",pairs[i].revenue);
}
}