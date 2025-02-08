typedef enum {failure,success} retstat;

typedef struct IdNode {
  struct IdNode *next;
  unsigned int id;
}IdNode;

typedef struct SmartGridTransaction{
  unsigned int transID;
  unsigned int sellerID;
  unsigned int buyerID;
  float amtOfEnergy;
  float pricePerKWh;
  char date[11];
  char time[6];
  int flag;
}SmartGridTransaction;

typedef struct TransNode{
  SmartGridTransaction entry;
  struct TransNode* next;
}TransNode;

typedef struct SellerAttrib{
  unsigned int sellerID;
  float b300;
  float a300;
  IdNode *regularBuyers;
}SellerAttrib;

typedef struct SellersList{
  SellerAttrib attributes;
  struct SellersList* next;
}SellersList;

typedef struct seller_buyer{
  unsigned int id;
  float revenue;
  float totalenergy;
  TransNode *memberhead;
  struct seller_buyer* next;
}seller_buyer;

typedef struct pair {
  int count;
  unsigned int sellerID;
  unsigned int buyerID; 
  struct pair* next;   
}Pair;

retstat addEntry(TransNode **,TransNode **,SellersList *);
void cleanTransList(TransNode **); 
void displayData(TransNode *);
void readTransactions(TransNode** , TransNode**);
void loadSellersFromFile(SellersList** , SellersList** );
void cleanSellersList(SellersList** );
void listTransinTime(TransNode*);
void saveTransactions(TransNode *);
TransNode* createTransNode(SmartGridTransaction *);
retstat createSellersList(seller_buyer**,TransNode*);
void clearSellersList(seller_buyer**);
retstat createBuyersList(seller_buyer**,TransNode*);
void clearBuyersList(seller_buyer**);
void sort_pairs(TransNode*);
void update(TransNode*);
TransNode* max_ener(TransNode *);
void revenueGenerated(seller_buyer *);
seller_buyer* calculateEnergy(seller_buyer *);
