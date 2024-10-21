#include "combined.h"
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