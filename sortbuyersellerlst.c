#include "combined.h"

void swap1(struct seller_buyer *a, struct seller_buyer *b) {
    struct seller_buyer temp=*a;
    *a=*b;
    *b=temp;
}
void swap2(float *a, float *b) {
    float temp=*a;
    *a=*b;
    *b=temp;
}
int partition2(struct seller_buyer lst[], int high, int low, float parameter[]) {
    float x=parameter[low];
    int i=low, j=high;

    while(i<j && parameter[i]<=x) i++;
    while(i<j && parameter[j]>x) j--;
    if(parameter[j]>x) j--;

    while(i<j) {
        swap2(&parameter[i],&parameter[j]);
        swap1(&lst[i],&lst[j]);
        while(i<j && parameter[i]<=x) i++;
        while(i<j && parameter[j]>x) j--;
    }

    return j;
}
void quickSort2(struct seller_buyer lst[], int high, int low, float parameter[]) {
    int p=partition2(lst,high,low,parameter);
    swap1(&lst[low],&lst[p]);
    swap2(&parameter[low],&parameter[p]);
    quickSort2(lst,p-1,low,parameter);
    quickSort2(lst,high,p+1,parameter);
}