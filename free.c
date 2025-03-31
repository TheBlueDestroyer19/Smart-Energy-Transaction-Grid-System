#include <stdlib.h>
#include <stdio.h>
#include "template.h"

void deleteTransTree(TransactionTree* root) {
  if (!root->is_leaf) 
    for (int i = 0; i <= root->numKeys; i++) 
      deleteTransTree(root->children[i]);

  free(root);
}
