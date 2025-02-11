#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "template.h"

void saveRegularBuyers(SellersList *sellerhead) {
  FILE *file = fopen("regularbuyers.txt", "w");
    
  SellersList *currentSeller=sellerhead;
  while(currentSeller) {
    fprintf(file,"%u,",currentSeller->attributes.sellerID);
        
    IdNode *buyer=currentSeller->attributes.regularBuyersHead;
    if (buyer==NULL)
      fprintf(file, "No regular buyer\n");
    else {
      while (buyer) {
        fprintf(file, "%u", buyer->id);
        if (buyer->next) fprintf(file, ",");
        buyer = buyer->next;
      }
      fprintf(file, "\n");
    }        
    currentSeller = currentSeller->next;
  }    
  fclose(file);
}
