#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "template.h"

void createListRegular(SellersList *sellerhead, seller_buyer *sellerlisthead) {
  SellersList* temp=sellerhead;
  seller_buyer* temp2=sellerlisthead;
  int count=0;

  while(temp2!=NULL) {
    TransNode *temp3=temp2->memberhead;
    while(temp3!=NULL) {

    }
  }
}
