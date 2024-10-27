#define SIZE 100
#include <stdio.h>
#include <string.h>

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
    float revenue;
    float energy;
};
//Structure to create the list for each buyer and seller

struct pair {
    int count;
    float revenue;
    unsigned int sellerID;
    unsigned int buyerID;    
};


void displayData(struct SmartGridTransaction transaction[], int filled)
{   int i=0;
    while(i<filled)
    {
        printf("Transaction Id: %d\n",transaction[i].transactionID);
        printf("Buyer Id: %d\n",transaction[i].buyerID);
        printf("Seller Id: %d\n",transaction[i].sellerID);
        printf("Amount of energy in kWh: %f\n",transaction[i].amountOfEnergy);
        printf("Price per kWh: %f\n",transaction[i].priceKWh);
        printf("The date is %s\n",transaction[i].date);
        printf("The time of transaction is %s\n\n",transaction[i].time);
        i++;
    }
}

//Initializes entire array to 0
void initializeZero(struct SmartGridTransaction record[], int size) {
    for (int i = 0; i < size; i++) {
        record[i].transactionID=0;
        record[i].buyerID=0;
        record[i].sellerID=0;
        record[i].amountOfEnergy=0.0;
        record[i].priceKWh=0.0;
        record[i].date[0]='\0';
        record[i].time[0]='\0';
        record[i].flag=0;
    }    
}

int inputValues(struct SmartGridTransaction record[], int filled, int size) {
    int trans_ID, buyer_ID, seller_ID;
    float amt_energy, price;
    char date_tr[20], time_tr[20];
    //Variables for each attribute

    printf("How many entries do you want to make?\n\n"); int numEntries;
    scanf("%d",&numEntries);

    for(int i=1;i<=numEntries && filled<=size;i++) {
        printf("Entry Number %d\n",i);

        printf("Enter the transaction ID:  ");
        scanf("%d",&trans_ID);
        int flag=0;
        for(int j=0;j<filled;j++) {
            if(trans_ID==record[j].transactionID) flag=1;
        }

        //Checking if the transaction ID already exists
        if(flag==1) {printf("A transaction with this ID already exists. Enter a new one please.\n"); i=i-1;}
        else {
            printf("Enter the buyer ID:  ");
            scanf("%d",&buyer_ID);

            printf("Enter the seller ID:  ");
            scanf("%d",&seller_ID);

            printf("Enter the amount of energy consumed:  ");
            scanf("%f",&amt_energy);

            printf("Enter the price per KWh:  ");
            scanf("%f",&price);

            printf("Enter the date of transaction in the format \"DD:MM:YYYY\":  ");
            scanf("%s",date_tr);

            printf("Enter the time of transaction in the format \"HH:MM:SS\":  ");
            scanf("%s",time_tr);
            printf("\n\n");

            record[filled].transactionID=trans_ID;
            record[filled].sellerID=seller_ID;
            record[filled].buyerID=buyer_ID;
            record[filled].amountOfEnergy=amt_energy;
            record[filled].priceKWh=price;
            strcpy(record[filled].date,date_tr);
            strcpy(record[filled].time,time_tr);
            //Atlast adding the new entry to the structure array

            filled=filled+1;
            //Number of elements incremented by 1
        }
        flag=0;
        //Flag value reset
    }
    return filled;
    //The number of elements in the array are returned
}

//List of buyers created in the same way as the list of sellers
int createListBuyer(struct SmartGridTransaction record[], int filled, struct seller_buyer buyerlst[],  int lstbuyerfilled) {
    int id, flag=0, p,flag2;
    for(int i=0;i<filled;i++) {
        id=record[i].buyerID;
        for(int k=0;k<lstbuyerfilled;k++) {
            if(id==buyerlst[k].ID) {flag=1; p=k;}
        }
        //Checking if the sellerID exists in the array
        if(flag==1) {
            int x=0; flag2=0;
            while(buyerlst[p].trans[x].transactionID!=0) {
                if(buyerlst[p].trans[x].transactionID==record[i].transactionID) flag2=1;
                x++;
            }
            if(flag2==0) {
                buyerlst[p].trans[x]=record[i];
            }
        }
        //Appending the array if found
        else {
            initializeZero(buyerlst[lstbuyerfilled].trans,SIZE);
            buyerlst[lstbuyerfilled].ID=id;
            p=0;
            for(int j=i;j<filled;j++) {                
                if(id==record[j].buyerID) {                    
                    buyerlst[lstbuyerfilled].trans[p]=record[j];
                    p++;
                }
            }
            lstbuyerfilled++;
        }
        //Creating a new entry only if not found
        flag=0;
        //Resetting flag
    }
    for(int i=0;i<lstbuyerfilled;i++) {
        printf("\n\n\nBuyer ID: %d\n\n",buyerlst[i].ID);
        p=0;
        while(buyerlst[i].trans[p].transactionID!=0) {
            printf("Transaction %d\n",(p+1));
            printf("Transaction ID: %d\n",buyerlst[i].trans[p].transactionID);
            printf("Seller ID: %d\n",buyerlst[i].trans[p].sellerID);
            printf("Amount of Energy: %f\n",buyerlst[i].trans[p].amountOfEnergy);
            printf("Price per KWh: %f\n",buyerlst[i].trans[p].priceKWh);
            printf("Date of transaction: %s\n",buyerlst[i].trans[p].date);
            printf("Time of transaction: %s\n\n",buyerlst[i].trans[p].time);
            p++;
        }
        printf("\n");
    }
    return lstbuyerfilled;
}



int createListSeller(struct SmartGridTransaction record[], int filled, struct seller_buyer sellerlst[],  int lstsellerfilled) {
    int id, flag=0, p, flag2=0;
    for(int i=0;i<filled;i++) {
        id=record[i].sellerID;
        for(int k=0;k<lstsellerfilled;k++) {
            if(id==sellerlst[k].ID) {flag=1; p=k;}
        }
        //Checking if the sellerID exists in the array
        if(flag==1) {
            int x=0; flag2=0;
            while(sellerlst[p].trans[x].transactionID!=0) {
                if(sellerlst[p].trans[x].transactionID==record[i].transactionID) flag2=1;
                x++;
            }
            if(flag2==0) {
                sellerlst[p].trans[x]=record[i];
            }
        }
        //Appending the array if found
        else {
            initializeZero(sellerlst[lstsellerfilled].trans,SIZE);
            sellerlst[lstsellerfilled].ID=id;
            p=0;
            for(int j=i;j<filled;j++) {                
                if(id==record[j].sellerID) {                    
                    sellerlst[lstsellerfilled].trans[p]=record[j];
                    p++;
                }
            }
            lstsellerfilled++;
        }
        //If it does not exist only then a new entry is added to sellerlst

        flag=0;
        //Flag is reset
    }
    for(int i=0;i<lstsellerfilled;i++) {
        printf("\n\n\nSeller ID: %d\n\n",sellerlst[i].ID);
        p=0;
        while(sellerlst[i].trans[p].transactionID!=0) {
            printf("Transaction %d\n",(p+1));
            printf("Transaction ID: %d\n",sellerlst[i].trans[p].transactionID);
            printf("Buyer ID: %d\n",sellerlst[i].trans[p].buyerID);
            printf("Amount of Energy: %f\n",sellerlst[i].trans[p].amountOfEnergy);
            printf("Price per KWh: %f\n",sellerlst[i].trans[p].priceKWh);
            printf("Date of transaction: %s\n",sellerlst[i].trans[p].date);
            printf("Time of transaction: %s\n\n",sellerlst[i].trans[p].time);
            p++;
        }
        printf("\n");
    }
    return lstsellerfilled;
}

int maxMonth(struct SmartGridTransaction transaction[],int filled)
{
    int A[12];
    for(int i=0;i<12;i++)
    A[i]=0;
    for(int i=0;i<filled;i++)
    {   
        int month=0;
        for (int j = 3; transaction[i].date[j] != ':'; j++) {
            month = month * 10 + (transaction[i].date[j] - 48);
        }
        
        A[month-1]++;        
    }
    int max=0;
    int max_m;
    
    for(int i=0;i<12;i++)
    {
        if(A[i]>max)
        {max=A[i];
        max_m=i+1;
        }
    }
    return max_m;
}


void list(struct SmartGridTransaction transaction[],int filled) {

    char start_date[11];
    char end_date[11];
    char start_time[11];
    char end_time[11];
    //Arrays of characters to store the starting and ending dates and time

    printf("Enter the starting date\n");
    scanf("%s",start_date);
    printf("Enter the ending date\n");
    scanf("%s",end_date);
    printf("Enter the starting time\n");

    int start_year=0,end_year=0;
    //Starting and ending years
    int start_month=0,end_month=0;
    //Starting and ending months
    int start_d=0,end_d=0;

    for (int i = 6; start_date[i] != '\0'; i++) {
            start_year = start_year * 10 + (start_date[i] - 48);
    }
    
    for (int i = 6; end_date[i] != '\0'; i++) {
            end_year = end_year * 10 + (end_date[i] - 48);
    }
    //Every character is extracted and then converted into number
    //Year starts from index 6 

    for (int i = 3; start_date[i] != ':'; i++) {
        start_month = start_month * 10 + (start_date[i] - 48);
    }
    
    for (int i = 3; end_date[i] != ':'; i++) {
            end_month = end_month * 10 + (end_date[i] - 48);
    }
    //Month starts at index 3 and ends when ':' is encountered
    for (int i = 0; start_date[i] != ':'; i++) {
        start_d = start_d * 10 + (start_date[i] - 48);
    }
    for (int i = 0; end_date[i] != ':'; i++) {
            end_d = end_d * 10 + (end_date[i] - 48);
    }
    //Date starts from index 0 and ends when ':' is encountered


    int i=0;
    while(i<filled)
    {   
        int flag=0;
        int year=0;
        for (int j = 6; transaction[i].date[j] != '\0'; j++) {
            year = year * 10 + (transaction[i].date[j] - 48);
        }
        int month=0;
        for (int j = 3; transaction[i].date[j] != ':';j++) {
            month = month * 10 + (transaction[i].date[j] - 48);
        }
        int date=0;
        for (int j = 0; transaction[i].date[j] != ':'; j++) { 
            date = date * 10 + (transaction[i].date[j] - 48);
        }
        //For every transaction date the year, month and date are extracted the same way as above
        if(!(year<start_year||((year==start_year)&&(month<start_month))||((year==start_year)&&(month==start_month)&&(date<start_d))||(year>end_year||((year==end_year)&&(month>end_month))||((year==end_year)&&(month==end_month)&&(date>end_d)))))
        flag=1;
       
        
        if(flag==1)
        {
            printf("\nTransaction no: %d\n",i+1);
            printf("Transaction Id:%d\n",transaction[i].transactionID);
            printf("Buyer Id:%d\n",transaction[i].buyerID);
            printf("Seller Id:%d\n",transaction[i].sellerID);
            printf("Amount of energy in kWh %f\n",transaction[i].amountOfEnergy);
            printf("Price per kWh:%f\n",transaction[i].priceKWh);
            printf("The date is %s\n",transaction[i].date);
            printf("The time of transaction is %s\n\n",transaction[i].time);
        }
        

       i++; 
    }


}

void totalRevenue(struct seller_buyer sellerlst[], int lstsellerfilled) {
    float sum; int j;
    
    for(int i=0;i<lstsellerfilled;i++) {
        sum=0; j=0;
        while(sellerlst[i].trans[j].transactionID!=0) {
            sum=sum+(sellerlst[i].trans[j].amountOfEnergy*sellerlst[i].trans[j].priceKWh);
            j++;
        }
        sellerlst[i].revenue=sum;
    }

    printf("How many sellers' revenue do you want see?\n");
    int numOfSellers; scanf("%d",&numOfSellers);
    int found=0;
    for(int i=1;i<=numOfSellers;i++) {
        printf("Enter the seller ID: "); int sID; scanf("%d",&sID);
        for(int j=0;j<lstsellerfilled;j++) {
            if(sellerlst[j].ID==sID) {
                printf("Total Revenue generated by %d is %f\n\n",sID,sellerlst[j].revenue);
                found=1;
            }
        } 
        if(found==0) printf("Seller ID not found\n\n");
        found=0;
    }
}

int partition_seller(struct seller_buyer lst[], int low, int high) {
    int i=low, j=high;
    float x=lst[low].revenue;
    while((i<j) && (lst[i].revenue<=x)) i++;
    while((i<j) && (lst[j].revenue>x)) j--;
    if(lst[j].revenue>x) j--;
    while(i<j) {
        struct seller_buyer temp=lst[i];
        lst[i]=lst[j];
        lst[j]=temp;
        i++;
        j--;
        while(lst[i].revenue<=x) i++;
        while(lst[j].revenue>x) j--;
    }
    return j;
}
void quicksort_seller(struct seller_buyer lst[], int low, int high) {
    if(low<high) {
        int p=partition_seller(lst,low,high);
        struct seller_buyer temp=lst[p];
        lst[p]=lst[low];
        lst[low]=temp;
        quicksort_seller(lst,low,p-1);
        quicksort_seller(lst,p+1,high);
    }
}

void sortSellerList(struct seller_buyer sellerlst[], int lstsellerfilled) {   
    
    quicksort_seller(sellerlst,0,lstsellerfilled-1);

    printf("The list of sellers after sorting:\n");
    for(int i=0;i<lstsellerfilled;i++) {
        printf("Seller ID: %d\n",sellerlst[i].ID);
        printf("Total revenue: %f\n\n",sellerlst[i].revenue);
    }
}

int partition_buyer(struct seller_buyer lst[], int low, int high) {
    int i=low, j=high;
    float x=lst[low].energy;
    while((i<j) && (lst[i].energy<=x)) i++;
    while((i<j) && (lst[j].energy>x)) j--;
    if(lst[j].energy>x) j--;
    while(i<j) {
        struct seller_buyer temp=lst[i];
        lst[i]=lst[j];
        lst[j]=temp;
        i++;
        j--;
        while(lst[i].energy<=x) i++;
        while(lst[j].energy>x) j--;
    }
    return j;
}
void quicksort_buyer(struct seller_buyer lst[], int low, int high) {
    if(low<high) {
        int p=partition_buyer(lst,low,high);
        struct seller_buyer temp=lst[p];
        lst[p]=lst[low];
        lst[low]=temp;
        quicksort_buyer(lst,low,p-1);
        quicksort_buyer(lst,p+1,high);
    }
}

void createAmtList(struct seller_buyer buyerlst[], int lstbuyerfilled) {
    float amount;
    int j;
    for(int i=0;i<lstbuyerfilled;i++) {
        amount=0; j=0;
        while(buyerlst[i].trans[j].transactionID!=0) {
            amount=amount+buyerlst[i].trans[j].amountOfEnergy;
            j++;
        }
        buyerlst[i].energy=amount;
    }
}
void sortBuyerList(struct seller_buyer buyerlst[], int lstbuyerfilled) {
    
    createAmtList(buyerlst, lstbuyerfilled);
    
    quicksort_buyer(buyerlst,0,lstbuyerfilled-1);

    printf("The list of buyers after sorting:\n");
    for(int i=0;i<lstbuyerfilled;i++) {
        printf("Buyer ID: %d\n",buyerlst[i].ID);
        printf("Total amount of energy bought: %f\n\n",buyerlst[i].energy);
    }
}


// Partition function
int partition_record(struct SmartGridTransaction record[], int high, int low) {
    float x=record[low].amountOfEnergy;
    int i=low, j=high;

    while(i<j && record[i].amountOfEnergy<=x) i++;
    while(i<j && record[j].amountOfEnergy>x) j--;
    if(record[j].amountOfEnergy>x) j--;

    while(i<j) {
        struct SmartGridTransaction temp=record[i];
        record[i]=record[j];
        record[j]=temp;
        i++; j--;
        //Value checking based on amount of energy while swapping the entire entry
        while(record[i].amountOfEnergy<=x) i++;
        while(record[j].amountOfEnergy>x) j--;
    }

    return j;
}

//Quicksort algoritm
void quickSort_record(struct SmartGridTransaction record[], int high, int low) {
    if(low<high) {
    int p=partition_record(record,high,low);
    struct SmartGridTransaction temp=record[low];
    record[low]=record[p];
    record[p]=temp;
    quickSort_record(record,p-1,low);
    quickSort_record(record,high,p+1);
    }
}


int maxTradingTrans(struct SmartGridTransaction record[], int filled) {

    quickSort_record(record,filled-1,0);
    
    printf("Sorted in order w.r.t the amount of energy traded:\n");
    displayData(record,filled);    
    return filled-1;
}

//Swapping pair type structure
void swap3(struct pair *a, struct pair *b) {
    struct pair temp=*a;
    *a=*b;
    *b=temp;
}





int partition3(struct pair record[], int high, int low) {
    float x=record[high].revenue;
    int i=low, j=high;

    while(i<j && record[i].revenue>x) i++;
    while(i<j && record[j].revenue<=x) j--;

    while(i<j) {
        swap3(&record[i],&record[j]);
        while(i<j && record[i].revenue>x) i++;
        while(i<j && record[j].revenue<=x) j--;
    }

    return i;
}

void quickSort3(struct pair record[], int high, int low) {
    if(low<high)
    {int p=partition3(record,high,low);
    swap3(&record[high],&record[p]);
    quickSort3(record,p-1,low);
    quickSort3(record,high,p+1);
    }
}

void sort_rev(struct SmartGridTransaction transaction[],int filled)
{
    struct pair pairs[SIZE];
    struct pair temp;
    int k=0;
    for(int i=0;i<filled;i++)
    {   
        if(transaction[i].flag!=1)
        {
         pairs[k].buyerID=transaction[i].buyerID;
         pairs[k].sellerID=transaction[i].sellerID;
         pairs[k].revenue=transaction[i].amountOfEnergy*transaction[i].priceKWh;
        for(int j=i+1;j<filled;j++)
        {
            if(pairs[k].buyerID==transaction[j].buyerID && pairs[k].sellerID==transaction[j].sellerID)
            {
                pairs[k].revenue+=transaction[j].amountOfEnergy*transaction[j].priceKWh;
                transaction[j].flag=1;
            
            }
        }
        k++;
        }
    }
    quickSort3(pairs,k-1,0);
    printf("seller/buyer pairs in decreasing order of the total revenue exchanged between them are \n");
for(int i=0;i<k;i++)
{
    printf("Buyer ID:%d\n",pairs[i].buyerID);
    printf("Seller ID:%d\n",pairs[i].sellerID);
    printf("revenue:%f\n\n",pairs[i].revenue);
}
}


int partition4(struct pair record[], int high, int low) {
    int x=record[high].count;
    int i=low, j=high;

    while(i<j && record[i].count>x) i++;
    while(i<j && record[j].count<=x) j--;

    while(i<j) {
        swap3(&record[i],&record[j]);
        while(i<j && record[i].count>x) i++;
        while(i<j && record[j].count<=x) j--;
    }

    return i;
}

void quickSort4(struct pair record[], int high, int low) {
    if(low<high)
    {
    int p=partition4(record,high,low);
    swap3(&record[high],&record[p]);
    quickSort4(record,p-1,low);
    quickSort4(record,high,p+1);
    }
}
void sort_trans(struct SmartGridTransaction transaction[],int filled)
{
    struct pair pairs[SIZE];
    struct pair temp;
    int k=0;
    for(int i=0;i<filled;i++)
    {   
        if(transaction[i].flag!=1)
        {
         pairs[k].count=1;
         pairs[k].buyerID=transaction[i].buyerID;
         pairs[k].sellerID=transaction[i].sellerID;

        for(int j=i+1;j<filled;j++)
        {
            if(pairs[k].buyerID==transaction[j].buyerID && pairs[k].sellerID==transaction[j].sellerID)
            {
                pairs[k].count++;
                transaction[j].flag=1;
            
            }
        }
        k++;
        }
    }
    
    quickSort4(pairs,k-1,0);

    printf("seller/buyer pairs in decreasing order of the number of transactions between them are \n");
    for(int i=0;i<k;i++)
    {
        printf("Buyer ID:%d\n",pairs[i].buyerID);
        printf("Seller ID:%d\n",pairs[i].sellerID);
        printf("Count:%d\n\n",pairs[i].count);
    }
}

void hardcode(struct SmartGridTransaction record[]) {
    // Manually initializing all 25 transactions

    // Transaction 1
    record[0].transactionID = 1;
    record[0].buyerID = 101;
    record[0].sellerID = 201;
    record[0].amountOfEnergy = 100.5;
    record[0].priceKWh = 3.5;
    strcpy(record[0].date, "15:10:2024");
    strcpy(record[0].time, "14:30");

    // Transaction 2
    record[1].transactionID = 2;
    record[1].buyerID = 102;
    record[1].sellerID = 202;
    record[1].amountOfEnergy = 250.2;
    record[1].priceKWh = 4.0;
    strcpy(record[1].date, "15:10:2024");
    strcpy(record[1].time, "10:00");

    // Transaction 3
    record[2].transactionID = 3;
    record[2].buyerID = 101;
    record[2].sellerID = 203;
    record[2].amountOfEnergy = 180.0;
    record[2].priceKWh = 3.8;
    strcpy(record[2].date, "10:09:2024");
    strcpy(record[2].time, "11:45");

    // Transaction 4
    record[3].transactionID = 4;
    record[3].buyerID = 103;
    record[3].sellerID = 204;
    record[3].amountOfEnergy = 320.7;
    record[3].priceKWh = 3.2;
    strcpy(record[3].date, "12:09:2024");
    strcpy(record[3].time, "12:15");

    // Transaction 5
    record[4].transactionID = 5;
    record[4].buyerID = 104;
    record[4].sellerID = 201;
    record[4].amountOfEnergy = 220.0;
    record[4].priceKWh = 3.9;
    strcpy(record[4].date, "20:08:2024");
    strcpy(record[4].time, "09:30");

    // Transaction 6
    record[5].transactionID = 6;
    record[5].buyerID = 102;
    record[5].sellerID = 202;
    record[5].amountOfEnergy = 190.0;
    record[5].priceKWh = 4.5;
    strcpy(record[5].date, "16:10:2024");
    strcpy(record[5].time, "14:00");

    // Transaction 7
    record[6].transactionID = 7;
    record[6].buyerID = 105;
    record[6].sellerID = 203;
    record[6].amountOfEnergy = 500.0;
    record[6].priceKWh = 2.9;
    strcpy(record[6].date, "25:07:2024");
    strcpy(record[6].time, "13:30");

    // Transaction 8
    record[7].transactionID = 8;
    record[7].buyerID = 101;
    record[7].sellerID = 201;
    record[7].amountOfEnergy = 300.0;
    record[7].priceKWh = 3.7;
    strcpy(record[7].date, "01:09:2024");
    strcpy(record[7].time, "15:00");

    // Transaction 9
    record[8].transactionID = 9;
    record[8].buyerID = 106;
    record[8].sellerID = 204;
    record[8].amountOfEnergy = 275.6;
    record[8].priceKWh = 4.0;
    strcpy(record[8].date, "15:10:2024");
    strcpy(record[8].time, "16:45");

    // Transaction 10
    record[9].transactionID = 10;
    record[9].buyerID = 101;
    record[9].sellerID = 203;
    record[9].amountOfEnergy = 330.0;
    record[9].priceKWh = 3.6;
    strcpy(record[9].date, "29:07:2024");
    strcpy(record[9].time, "17:30");

    // Transaction 11
    record[10].transactionID = 11;
    record[10].buyerID = 107;
    record[10].sellerID = 205;
    record[10].amountOfEnergy = 110.5;
    record[10].priceKWh = 3.3;
    strcpy(record[10].date, "02:08:2024");
    strcpy(record[10].time, "11:00");

    // Transaction 12
    record[11].transactionID = 12;
    record[11].buyerID = 101;
    record[11].sellerID = 202;
    record[11].amountOfEnergy = 150.5;
    record[11].priceKWh = 3.4;
    strcpy(record[11].date, "20:09:2024");
    strcpy(record[11].time, "09:00");

    // Transaction 13
    record[12].transactionID = 13;
    record[12].buyerID = 108;
    record[12].sellerID = 201;
    record[12].amountOfEnergy = 130.2;
    record[12].priceKWh = 3.9;
    strcpy(record[12].date, "05:08:2024");
    strcpy(record[12].time, "18:00");

    // Transaction 14
    record[13].transactionID = 14;
    record[13].buyerID = 109;
    record[13].sellerID = 202;
    record[13].amountOfEnergy = 210.8;
    record[13].priceKWh = 3.8;
    strcpy(record[13].date, "25:09:2024");
    strcpy(record[13].time, "10:45");

    // Transaction 15
    record[14].transactionID = 15;
    record[14].buyerID = 105;
    record[14].sellerID = 204;
    record[14].amountOfEnergy = 280.0;
    record[14].priceKWh = 3.5;
    strcpy(record[14].date, "05:10:2024");
    strcpy(record[14].time, "19:30");

    // Transaction 16
    record[15].transactionID = 16;
    record[15].buyerID = 102;
    record[15].sellerID = 201;
    record[15].amountOfEnergy = 400.0;
    record[15].priceKWh = 4.2;
    strcpy(record[15].date, "30:07:2024");
    strcpy(record[15].time, "13:00");

    // Transaction 17
    record[16].transactionID = 17;
    record[16].buyerID = 110;
    record[16].sellerID = 203;
    record[16].amountOfEnergy = 370.9;
    record[16].priceKWh = 3.4;
    strcpy(record[16].date, "10:10:2024");
    strcpy(record[16].time, "15:15");

    // Transaction 18
    record[17].transactionID = 18;
    record[17].buyerID = 106;
    record[17].sellerID = 201;
    record[17].amountOfEnergy = 295.5;
    record[17].priceKWh = 4.1;
    strcpy(record[17].date, "13:10:2024");
    strcpy(record[17].time, "12:00");

    // Transaction 19
    record[18].transactionID = 19;
    record[18].buyerID = 109;
    record[18].sellerID = 202;
    record[18].amountOfEnergy = 305.3;
    record[18].priceKWh = 3.7;
    strcpy(record[18].date, "22:09:2024");
    strcpy(record[18].time, "14:45");

    // Transaction 20
    record[19].transactionID = 20;
    record[19].buyerID = 104;
    record[19].sellerID = 205;
    record[19].amountOfEnergy = 250.0;
    record[19].priceKWh = 3.9;
    strcpy(record[19].date, "18:09:2024");
    strcpy(record[19].time, "16:30");

    // Transaction 21
    record[20].transactionID = 21;
    record[20].buyerID = 108;
    record[20].sellerID = 203;
    record[20].amountOfEnergy = 415.0;
    record[20].priceKWh = 3.5;
    strcpy(record[20].date, "01:10:2024");
    strcpy(record[20].time, "09:00");

    // Transaction 22
    record[21].transactionID = 22;
    record[21].buyerID = 103;
    record[21].sellerID = 204;
    record[21].amountOfEnergy = 175.0;
    record[21].priceKWh = 3.6;
    strcpy(record[21].date, "10:09:2024");
    strcpy(record[21].time, "10:00");

    // Transaction 23
    record[22].transactionID = 23;
    record[22].buyerID = 110;
    record[22].sellerID = 205;
    record[22].amountOfEnergy = 510.0;
    record[22].priceKWh = 3.9;
    strcpy(record[22].date, "25:09:2024");
    strcpy(record[22].time, "12:30");

    // Transaction 24
    record[23].transactionID = 24;
    record[23].buyerID = 105;
    record[23].sellerID = 202;
    record[23].amountOfEnergy = 190.5;
    record[23].priceKWh = 4.0;
    strcpy(record[23].date, "05:10:2024");
    strcpy(record[23].time, "08:45");

    // Transaction 25
    record[24].transactionID = 25;
    record[24].buyerID = 106;
    record[24].sellerID = 203;
    record[24].amountOfEnergy = 270.0;
    record[24].priceKWh = 4.2;
    strcpy(record[24].date, "17:10:2024");
    strcpy(record[24].time, "17:00");
}

void pairWithMaxTrans(struct SmartGridTransaction record[], int filled) {
    int buyer_ID, seller_ID;
    
    int count=1,maxcnt=1, maxtimebID,maxtimesID;
    //To count and check which buyer-seller pair appears for the maximum number of times
    for(int i=0;i<filled-1;i++) {
        buyer_ID=record[i].buyerID;
        seller_ID=record[i].sellerID;

        for(int j=i+1;j<filled;j++) {
            if(buyer_ID==record[j].buyerID && seller_ID==record[j].sellerID)
                count++;
            //Increment if the buyer-seller pairs are encountered ahead
        }
        if(maxcnt<count) {
            maxcnt=count;
            maxtimebID=buyer_ID;
            maxtimesID=seller_ID;
        }
        //Maxcheck

        count=1;
        //count reinitialized to 1
    }
    printf("The buyer-seller pair which occurs for the maximum number of times is:\n");
    printf("Buyer ID: %d\tSeller ID: %d\n\n",maxtimebID,maxtimesID);
}

int main() {

    int choice=-1;
    //Stores the choice entered by the user to process the further switch case. User can enter any of the options mentioned ahead
    int filled=0;
    //Variable to keep the track of the number of rows filled in the main "Energy_Trans" array of the main structure
    int month;
    //Stores the month in which maximum transactions take place
    int lstsellerfilled=0, lstbuyerfilled=0;
    //Variables to keep the track of number of rows filled in the list of sellers and buyers respectively
    int max_trans_index;
    //Stores the index of maximum amount of energy traded in the list of all transactions

    struct SmartGridTransaction Energy_Trans[SIZE];
    //Array of the main structure which contains the attribures such as Transaction ID, Buyer ID, Seller ID, and so on
    struct seller_buyer ListTransSeller[SIZE];
    //List of each seller. It contains all the transactions of every seller
    struct seller_buyer ListTransBuyer[SIZE];
    //List of each buyer. It contains all the transactions of every buyer

    

    
    hardcode(Energy_Trans);
    //Function to initially enter 25 values in the structure
    filled=25;
    //Update filled to 25 after entering the initial values


    printf("Greetings to the user!\nHere are a bunch of operations.\nWhich one do you like to do?\n\n");
    while(choice != 0) {    

        printf("1. To add new entries enter 1\n"); //S
        printf("2. To display the values enter 2\n"); //D
        printf("3. To create a list for every seller enter 3\n"); //S
        printf("4. To create a list for every buyer enter 4\n"); //S
        printf("5. To get the number of transactions in a given time period enter 5\n"); //D
        printf("6. To find the month in which maximum transactions took place enter 6\n"); //D
        printf("7. To calculate the total revenue generated by a seller enter 7\n"); //S
        printf("8. To sort the list of sellers based on the revenue generated enter 8\n"); //S
        printf("9. To find the transaction with the highest amount of energy transaction enter 9\n"); //S,D
        printf("10. To sort the list of buyers based on the energy bought enter 10\n"); //S
        printf("11. To find out a pair of buyer and seller involved in the maximum transaction enter 11\n"); //S
        printf("12. To sort all buyer-seller pairs in the decreasing order of the number of transactions between them enter 12\n"); //D
        printf("13. To sort all buyer-seller pairs in the decreasing order of the revenue exchanged between them enter 13\n"); //D
        printf("14. To exit the application enter 0\n\n");

        scanf("%d",&choice);

        switch(choice) {

            case 1:
                filled=inputValues(Energy_Trans, filled,SIZE);
            break;

            case 2:                
                displayData(Energy_Trans,filled);
            break;

            case 3:
                lstsellerfilled=createListSeller(Energy_Trans,filled,ListTransSeller,lstsellerfilled);
            break;

            case 4:
                lstbuyerfilled=createListBuyer(Energy_Trans,filled,ListTransBuyer,lstbuyerfilled);
            break;

            case 5:
                list(Energy_Trans,filled);
            break;

            case 6:                
                month=maxMonth(Energy_Trans,filled);
                char monthName[12][10]={"January","February","March","April","May","June","July","August","September","October","November","December"};
                printf("The month in which maximum transactions occur is %s\n\n", monthName[month-1]);                
            break;

            case 7:
                if(lstsellerfilled==0) printf("The list of sellers has not been created.");
                else totalRevenue(ListTransSeller,lstsellerfilled);
            break;

            case 8:
                if(ListTransSeller[0].revenue==0) {
                    if(lstsellerfilled!=0) printf("Please create the list of revenues for sellers using '7'\n");
                    else printf("Please create the list of sellers using '3' and then create the list of revenues using '7'"); 
                }
                else sortSellerList(ListTransSeller,lstsellerfilled);
            break;

            case 9:               
                max_trans_index=maxTradingTrans(Energy_Trans,filled);
                printf("The maximum energy transaction occured at:\n");
                printf("Transaction ID: %d\n",Energy_Trans[max_trans_index].transactionID);
                printf("Amount of energy traded: %f KWh\n",Energy_Trans[max_trans_index].amountOfEnergy);
                printf("Date: %s\n",Energy_Trans[max_trans_index].date);
                printf("Seller: %d\tBuyer: %d\n\n",Energy_Trans[max_trans_index].sellerID,Energy_Trans[max_trans_index].buyerID);                
            break;

            case 10:
                if(lstbuyerfilled==0) printf("The list of buyers is empty. Please create it using '4'\n");
                else sortBuyerList(ListTransBuyer,lstbuyerfilled);
            break;

            case 11:
                pairWithMaxTrans(Energy_Trans,filled);
            break;

            case 12:
                sort_trans(Energy_Trans, filled);
            break;

            case 13:
                sort_rev(Energy_Trans, filled);
            break;

            default:
                choice = 0;
        }
    }
} 