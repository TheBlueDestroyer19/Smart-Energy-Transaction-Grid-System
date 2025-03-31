#define MAX 4
#define MIN 2
#define MAX_LINE_LENGTH 256

typedef struct Transaction{
  unsigned int transID;
  unsigned int sellerID;
  unsigned int buyerID;
  float amtOfEnergy;
  float pricePerKWh;
  float total_price;
  char date[11];
  char time[6];
}Transaction;

typedef struct TransactionTree{
  int numKeys;
  int is_leaf;
  struct TransactionTree* children[MAX+1];
  struct TransactionTree* next;
  union {
    unsigned int keys[MAX];
    Transaction trans[MAX];
  }data;
}TransactionTree;

typedef struct buyerNode{
  unsigned int buyerID;
  struct buyerNode* next;
}buyerNode;

typedef struct SellerData{
  unsigned int sellerID;
  float a300;
  float b300;
  float revenue;
  buyerNode* head;
  buyerNode* tail;
  TransactionTree* subtree;
}SellerData;

typedef struct SellerTree{
  int numKeys;
  int is_leaf;
  struct SellerTree* children[MAX+1];
  struct SellerTree* next;
  union {
    unsigned int keys[MAX];
    SellerData sellerdata[MAX];
  }data;
}SellerTree;

typedef struct BuyerData{
  unsigned int buyerID;
  float total_energy;
  TransactionTree* subtree;
}BuyerData;

typedef struct BuyerTree{
  int numKeys;
  int is_leaf;
  struct BuyerTree* children[MAX+1];
  struct BuyerTree* next;
  union{
    unsigned int keys[MAX];
    BuyerData sellerdata[MAX];
  }data;
}BuyerTree;

typedef struct pair{
  unsigned int buyerID;
  unsigned int sellerID;
  int transCount;
  float revExchange;
}pair;

TransactionTree* addTransaction(TransactionTree* , SellerTree*);
TransactionTree* addTransactionsFromFile(TransactionTree*);
TransactionTree* createNode(int);
void displayTransactions(TransactionTree*);
void deleteTransTree(TransactionTree*);
void saveTransactionsToCSV(TransactionTree* );
