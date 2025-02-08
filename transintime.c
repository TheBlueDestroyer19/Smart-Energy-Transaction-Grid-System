#include<stdio.h>
#include "template.h"
void listTransinTime(TransNode * mainhead) {

  char start_date[11];
  char end_date[11];
  char start_time[11];
  char end_time[11];

  printf("Enter the starting date\n");
  scanf("%s",start_date);
  printf("Enter the ending date\n");
  scanf("%s",end_date);
  TransNode* temp=mainhead;


  int start_year=0,end_year=0;
  //Starting and ending years
  int start_month=0,end_month=0;
  //Starting and ending months
  int start_d=0,end_d=0;
  //Starting and ending dates

  for (int i=6;start_date[i]!='\0';i++) 
    start_year=start_year*10+(start_date[i]-48);
    
  for (int i=6;end_date[i]!='\0';i++) 
    end_year=end_year*10+(end_date[i]-48);
    //Every character is extracted and then converted into number
    //Year starts from index 6 

  for (int i = 3; start_date[i] != ':'; i++) 
    start_month = start_month * 10 + (start_date[i] - 48);
    
  for (int i = 3; end_date[i] != ':'; i++) 
    end_month = end_month * 10 + (end_date[i] - 48);
    //Month starts at index 3 and ends when ':' is encountered
  for (int i = 0; start_date[i] != ':'; i++) 
    start_d = start_d * 10 + (start_date[i] - 48);
    
  for (int i = 0; end_date[i] != ':'; i++) 
    end_d = end_d * 10 + (end_date[i] - 48);
    //Date starts from index 0 and ends when ':' is encountered

  while(temp!=NULL) {   
    int flag=0;
    int year=0;
    for (int j = 6; temp->entry.date[j] != '\0'; j++) 
year = year * 10 + (temp->entry.date[j] - 48);

    int month=0;
    for (int j = 3; temp->entry.date[j] != ':';j++) 
      month = month * 10 + (temp->entry.date[j] - 48);

    int date=0;
    for (int j = 0; temp->entry.date[j] != ':'; j++) 
      date = date * 10 + (temp->entry.date[j] - 48);

    //For every transaction date the year, month and date are extracted the same way as above
    if(!(year<start_year||((year==start_year)&&(month<start_month))||((year==start_year)&&(month==start_month)&&(date<start_d))||(year>end_year||((year==end_year)&&(month>end_month))||((year==end_year)&&(month==end_month)&&(date>end_d))))) 
      flag=1;
       
        
    if(flag==1) {
      //printf("\nTransaction no: %d\n",i+1);
      printf("Transaction Id:%d\n",temp->entry.transID);
      printf("Buyer Id:%d\n",temp->entry.buyerID);
      printf("Seller Id:%d\n",temp->entry.sellerID);
      printf("Amount of energy in kWh %f\n",temp->entry.amtOfEnergy);
      printf("Price per kWh:%f\n",temp->entry.pricePerKWh);
      printf("The date is %s\n",temp->entry.date);
      printf("The time of transaction is %s\n\n",temp->entry.time);
    }       

    temp=temp->next;
  }
}
