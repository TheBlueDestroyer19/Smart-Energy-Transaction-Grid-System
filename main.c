#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "template.h"

int main() {

  int choice;
  TransNode *mainhead=NULL, *maintail=NULL, *temp;
  SellersList *sellerhead=NULL, *sellertail=NULL;
  seller_buyer *sellerlisthead=NULL;
  seller_buyer *buyerlisthead=NULL;
  retstat status_code;
  
  loadSellersFromFile(&sellerhead,&sellertail);
  readTransactions(&mainhead,&maintail);

  do {
    printf("\n=======================================\n");
    printf("Energy Trading System Menu:\n");
    printf("=======================================\n");
    printf("1. Add New Transaction\n");
    printf("2. Display All Transactions\n");
    printf("3. List Transactions by Seller\n");
    printf("4. List Transactions by Buyer\n");
    printf("5. List Transactions in a Given Time Period\n");
    printf("6. Calculate Total Revenue by Seller\n");
    printf("7. Find Transaction with Highest Energy Amount\n");
    printf("8. Sort Buyers by Energy Bought\n");
    printf("9. Sort Seller/Buyer Pairs by Number of Transactions\n");
    printf("10. Update Transaction\n");
    printf("0. Exit\n");
    printf("=======================================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1: 
        status_code=addEntry(&mainhead,&maintail,sellerhead);
        if(status_code==failure) printf("Failed to add the entry!!\n");
        else printf("Successfully added the entry!!\n");
      break;

      case 2:
        displayData(mainhead);
      break;

      case 3: 
        createSellersList(&sellerlisthead,mainhead);
      break;

      case 4:
        createBuyersList(&buyerlisthead,mainhead);
      break;

      case 5: 
        listTransinTime(mainhead);
      break;

      case 6:
        revenueGenerated(sellerlisthead);
      break;

      case 7:
        mainhead=max_ener(mainhead);
        temp=mainhead;
        while(temp->next!=NULL) temp=temp->next;
        maintail=temp;
      break;

      case 8:
        buyerlisthead=calculateEnergy(buyerlisthead);
      break;

      case 9:
        sort_pairs(mainhead);
      break;

      case 10:
        update(mainhead);
      break;

      case 0:
        printf("Exiting program...\n"); 
      break;

      default: printf("Invalid choice! Please enter a valid option.\n");
    }
  } while (choice != 0);


  saveTransactions(mainhead);

  cleanTransList(&mainhead);
  clearSellersList(&sellerlisthead);
  clearSellersList(&buyerlisthead);
  cleanSellersList(&sellerhead);
}
