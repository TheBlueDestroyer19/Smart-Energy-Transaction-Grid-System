#include "combined.h"
#include <stdio.h>


int partition4(struct pair record[], int high, int low) {
    float x=record[low].revenue;
    int i=low, j=high;

    while(i<j && record[i].revenue>=x) i++;
    while(i<j && record[j].revenue<x) j--;

    while(i<j) {
        swap3(&record[i],&record[j]);
        while(i<j && record[i].revenue>=x) i++;
        while(i<j && record[j].revenue<x) j--;
    }

    return j;
}

void quickSort4(struct pair record[], int high, int low) {
    int p=partition4(record,high,low);
    swap3(&record[low],&record[p]);
    quickSort4(record,p-1,low);
    quickSort4(record,high,p+1);
}
void sort_trans(struct SmartGridTransaction transaction[],int filled)
{
    struct pair pairs[SIZE];
    struct pair temp;
    int k=0;
    for(int i=0;i<filled;i++)
    {   
        if(transaction[i].flag!=1)
        {
         pairs[k].count=1;
         pairs[k].buyerID=transaction[i].buyerID;
         pairs[k].sellerID=transaction[i].sellerID;

        for(int j=i+1;j<filled;j++)
        {
            if(pairs[k].buyerID==transaction[j].buyerID && pairs[k].sellerID==transaction[j].sellerID)
            {
                pairs[k].count++;
                transaction[j].flag=1;
            
            }
        }
        k++;
        }
    }
    
    quickSort4(pairs,k-1,0);

    printf("seller/buyer pairs in decreasing order of the number of transactions between them are \n");
    for(int i=0;i<k;i++)
    {
        printf("Buyer ID:%d\n",pairs[i].buyerID);
        printf("Seller ID:%d\n",pairs[i].sellerID);
        printf("Count:%d\n\n",pairs[i].count);
    }
}

