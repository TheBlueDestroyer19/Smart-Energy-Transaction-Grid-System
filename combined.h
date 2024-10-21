#ifndef COMBINED_H
#define COMBINED_H
#define SIZE 100

struct SmartGridTransaction {
    unsigned int transactionID;
    unsigned int buyerID;
    unsigned int sellerID;
    float amountOfEnergy;
    float priceKWh;
    char date[20];
    char time[20];
    int flag;
};
//Structure to create the basic database of all transactions

struct seller_buyer {
    unsigned int ID;
    struct SmartGridTransaction trans[SIZE];
};
//Structure to create the list for each buyer and seller

struct pair {
    int count;
    float revenue;
    unsigned int sellerID;
    unsigned int buyerID;    
};
//Structure to count number of occurances of each buyer-seller pairs and also to calculate the total revenue


void initializeZero(struct SmartGridTransaction record[], int size);
void hardcode(struct SmartGridTransaction record[]);
int inputValues(struct SmartGridTransaction record[], int filled, int size);
int maxMonth(struct SmartGridTransaction transaction[],int filled);
void displayData(struct SmartGridTransaction transaction[], int filled);
int createListBuyer(struct SmartGridTransaction record[], int filled, struct seller_buyer buyerlst[],  int lstbuyerfilled);
int createListSeller(struct SmartGridTransaction record[], int filled, struct seller_buyer sellerlst[],  int lstsellerfilled);
void list(struct SmartGridTransaction transaction[],int filled);
void totalRevenue(struct seller_buyer sellerlst[], float revenueGen[], int lstsellerfilled);
void sortSellerList(struct seller_buyer sellerlst[], int lstsellerfilled, float revenueGen[]);
int maxTradingTrans(struct SmartGridTransaction record[], int filled);
void sortBuyerList(struct seller_buyer buyerlst[], float energyBought[], int lstbuyerfilled);
void pairWithMaxTrans(struct SmartGridTransaction record[], int filled);
void sort_trans(struct SmartGridTransaction transaction[],int filled);
void sort_rev(struct SmartGridTransaction transaction[],int filled);
void quickSort2(struct seller_buyer lst[], int high, int low, float parameter[]);
void swap3(struct pair *a, struct pair *b);

#endif