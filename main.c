#include <stdio.h>
#include "template.h"

int main() {
  int choice=1;
  TransactionTree *transRoot=createNode(1);
  SellerTree *sellerRoot=NULL;

  transRoot=addTransactionsFromFile(transRoot);

  while(choice) {
    printf("\n==============================================\n");
    printf("             SMART GRID TRANSACTION SYSTEM      \n");
    printf("==============================================\n");
    printf("  1. Add New Transaction\n");
    printf("  2. Display All Transactions\n");
    printf("  3. Create a set of Transactions for Every Seller\n");
    printf("  4. Create a set of Transactions for Every Buyer\n");
    printf("  5. Find all transactions in a Given Time Period\n");
    printf("  6. Calculate Total Revenue by Seller\n");
    printf("  7. Find and Display Transactions in Energy Range\n");
    printf("  8. Sort Buyers Based on Energy Bought\n");
    printf("  9. Sort Seller/Buyer Pairs by Number of Transactions\n");
    printf("  0. Exit\n");
    printf("==============================================\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1: transRoot=addTransaction(transRoot,sellerRoot); break;
      case 2: displayTransactions(transRoot); break;
      //case 3: createSellerTransactions(); break;
      //case 4: createBuyerTransactions(); break;
      //case 5: findTransactionsByTimePeriod(); break;
      //case 6: calculateRevenueBySeller(); break;
      //case 7: findTransactionsByEnergyRange(); break;
      //case 8: sortBuyersByEnergyBought(); break;
      //case 9: sortSellerBuyerPairsByNoT(); break;
      case 0: printf("\nExiting program...\n"); break;
      default: printf("\n[!] Invalid choice! Please try again.\n");
    }
  }

  saveTransactionsToCSV(transRoot);
  printf("Clearing the transaction tree....");
  deleteTransTree(transRoot);
  printf("Done\n");
  return 0;
}
