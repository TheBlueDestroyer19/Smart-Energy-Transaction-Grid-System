#include "combined.h"
#include <stdio.h>

void sortSellerList(struct seller_buyer sellerlst[], int lstsellerfilled, float revenueGen[]) {
    quickSort2(sellerlst,lstsellerfilled-1,0,revenueGen);

    printf("The list of sellers after sorting:\n");
    for(int i=0;i<lstsellerfilled;i++) {
        printf("Seller ID: %d\n",sellerlst[i].ID);
        printf("Total revenue: %f\n\n",revenueGen[i]);
    }
}