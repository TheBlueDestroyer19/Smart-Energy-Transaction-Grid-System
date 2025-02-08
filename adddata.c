#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "template.h"

int isValidDate(char *date) {
  int valid=1;
  int day, month, year;
  int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  if(strlen(date)!=10 || date[2]!=':' || date[5]!=':') valid=0;
  if(sscanf(date, "%2d:%2d:%4d", &day, &month, &year) != 3) valid=0;
  if(month<1 || month>12) valid=0;
  if(day<1 || day>31) valid=0;
  if((year%4==0 && year%100!=0) || (year%400==0)) daysInMonth[1]=29;
  if(day>daysInMonth[month-1]) valid=0;
    
  return valid;
}

int isValidTime(char *time) {
  int valid=1;
  int hours, minutes;

  if(strlen(time)!=5 || time[2]!=':') valid=0;
  if(sscanf(time,"%2d:%2d",&hours,&minutes)!=2) valid=0;
  if(hours<0 || hours>23) valid=0;
  if(minutes<0 || minutes>59) valid=0;
    
  return valid;
}

int isValidID(unsigned int transID, TransNode *mainhead) {
  TransNode *temp=mainhead;
  int found=0;
  while(temp!=NULL && !found) {
    if(temp->entry.transID==transID) found=1; 
    else temp=temp->next;
  }
  return (!found);
}

retstat addEntry(TransNode **mainhead,TransNode **maintail,SellersList *sellerhead) {
  retstat status_code=success;
  unsigned int id; float x; char date[20], time[10];
  SellersList *temp=sellerhead;
  int found=0;
  TransNode *nptr=(TransNode*)malloc(sizeof(TransNode));

  if(nptr==NULL) {
    status_code=failure;
    printf("Memory allocation failed!!\n");
  }
  else {
    nptr->next=NULL;
  
    printf("Enter the transaction ID: "); scanf("%u",&id);
    while(!isValidID(id,*mainhead)) {
      printf("A transaction with the ID already exists!!\nRe-enter the transaction ID: ");
      scanf("%u",&id);
    }
    nptr->entry.transID=id;

    printf("Enter the seller ID: "); scanf("%u",&id);
    nptr->entry.sellerID=id;

    printf("Enter the buyer ID: "); scanf("%u",&id);
    nptr->entry.buyerID=id;
    getchar();

    printf("Enter the amount of energy traded: "); scanf("%f",&x);
    nptr->entry.amtOfEnergy=x;

    printf("Enter the date of transaction (format: DD:MM:YYYY): "); scanf("%s",date);
    while(!isValidDate(date)) {
      printf("The date is incorrect!!\nPlease re-enter the date: ");
      scanf("%s",date);
    }
    strcpy(nptr->entry.date,date);

    printf("Enter the time of transaction (format: HH:MM): "); scanf("%s",time);
    while(!isValidTime(time)) {
      printf("The time is incorrect!!\nPlease re-enter the time: ");
      scanf("%s",time);
    }
    strcpy(nptr->entry.time,time);

    x=nptr->entry.amtOfEnergy;
    id=nptr->entry.sellerID;
    while(temp!=NULL && !found) {
      if(temp->attributes.sellerID == id) {
        found=1;
        if(x>=300) nptr->entry.pricePerKWh=temp->attributes.a300;
        else nptr->entry.pricePerKWh=temp->attributes.b300;
      }
      else temp=temp->next;
    }
    if(!found) {
      status_code=failure;
      printf("Seller not found!!\n");
      free(nptr);
    }
  }

  if(status_code==success) {
    if(*mainhead==NULL) {
      *mainhead=nptr;
      *maintail=nptr;
    }
    else {
      (*maintail)->next=nptr;
      *maintail=nptr;
    }
  }

  return status_code;
}
