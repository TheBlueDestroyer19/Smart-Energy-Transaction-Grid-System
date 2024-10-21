#include<stdio.h>
#include"combined.h"
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
        if(year>start_year&&year<end_year)
        flag=1;
        else if(year==start_year)
        {
            if(month>start_month)
            flag=1;
            else if(month==start_month)
            {
                if(date>=start_d)
                flag=1;
            }
        }
        else if(year==end_year)
        {
            if(month<end_month)
            flag=1;
            if(month==end_month)
            {
                if(date<=end_d)
                flag=1;
            }
        }
        if(flag==1)
        {
            printf("Transaction no: %d\n",i+1);
            printf("Transaction Id:%d\n",transaction[i].transactionID);
            printf("Buyer Id:%d\n",transaction[i].buyerID);
            printf("Seller Id:%d\n",transaction[i].sellerID);
            printf("Amount of energy in kWh %d\n",transaction[i].amountOfEnergy);
            printf("Price per kWh:%d\n",transaction[i].priceKWh);
            printf("The date is %s\n",transaction[i].date);
            printf("The time of transaction is %s\n",transaction[i].time);
        }
        //Checking if the current date is greater than the start date and less than end date and if so, the transaction is printed

       i++; 
    }


}