#include <stdio.h>
#include <stdlib.h>
#include "template.h"

void saveTransactions(TransNode *head) {
  FILE *file = fopen("transactions.txt", "w");
  if (!file) {
    perror("Error opening file");
  }
  else {
    TransNode *temp = head;
    while (temp) {
      fprintf(file, "%u,%u,%u,%.2f,%.2f,%s,%s\n",
      temp->entry.transID,
      temp->entry.sellerID,
      temp->entry.buyerID,
      temp->entry.amtOfEnergy,
      temp->entry.pricePerKWh,
      temp->entry.date,
      temp->entry.time);
      temp = temp->next;
    }
    printf("Transactions saved successfully to transactions.txt\n");
    fclose(file);
  }
}
