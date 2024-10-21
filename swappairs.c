#include "combined.h"

//Swapping pair type structure
void swap3(struct pair *a, struct pair *b) {
    struct pair temp=*a;
    *a=*b;
    *b=temp;
}