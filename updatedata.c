#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "template.h"

void update(TransNode* mainhead)
{
    printf("Enter the transaction ID to update\n");
    int id;
    scanf("%d",&id);
    TransNode* temp=mainhead;
    int flag=0;
    while(temp!=NULL&&flag==0)
    {
        if(temp->entry.transID==id)
        flag=1;
        else
        temp=temp->next;
        
    }
    if(flag==1)
    {
        printf("Enter the new amount of energy\n");
        float amt;
        scanf("%f",&amt);
        printf("Enter the new Price Per kWh\n");
        float price;
        scanf("%f",&price);
        temp->entry.amtOfEnergy=amt;
        temp->entry.pricePerKWh=price;

    }
    else 
          printf("No such transaction exists with the given Transaction ID\n");
    
    

}
