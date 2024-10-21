#include <stdio.h>
#include "combined.h"
//Function to swap the values of struct SmartGridTransaction pointers
void swap(struct SmartGridTransaction *a, struct SmartGridTransaction *b) {
    struct SmartGridTransaction temp=*a;
    *a=*b;
    *b=temp;
}

//Partition algorithm
int partition(struct SmartGridTransaction record[], int high, int low) {
    float x=record[low].amountOfEnergy;
    int i=low, j=high;

    while(i<j && record[i].amountOfEnergy<=x) i++;
    while(i<j && record[j].amountOfEnergy>x) j--;
    if(record[i].amountOfEnergy>x) j--;

    while(i<j) {
        swap(&record[i],&record[j]);
        //Value checking based on amount of energy while swapping the entire entry
        while(i<j && record[i].amountOfEnergy<=x) i++;
        while(i<j && record[j].amountOfEnergy>x) j--;
    }

    return j;
}

//Quicksort algoritm
void quickSort(struct SmartGridTransaction record[], int high, int low) {
    int p=partition(record,high,low);
    swap(&record[low],&record[p]);
    quickSort(record,p-1,low);
    quickSort(record,high,p+1);
}
int maxTradingTrans(struct SmartGridTransaction record[], int filled) {
    quickSort(record,filled-1,0);
    printf("Sorted in order w.r.t the amount of energy traded:\n");
    displayData(record,filled);    
    return filled-1;
}