#include <stdio.h>
#include <stdlib.h>

void MaxSubseSum(int n);
int main(void) 
{
    int n;
    scanf("%d",&n);
    MaxSubseSum(n);
    return 0;
}
void MaxSubseSum(int n)
{
    int i,ThisSum=0,MaxSum=0,start=0,end=0,start1=0,flag=0;
    int a[n]; 
    for(i=0;i<n;i++)
    {
       scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        ThisSum += a[i];
        if(a[i]>=0)
        flag = 1;
        if(ThisSum > MaxSum)
        {
            start = start1;    
            MaxSum = ThisSum;
            end = i;
        }
        else if (ThisSum < 0)
        {
            ThisSum = 0;
            start1=i+1;
        }
    }
    if(MaxSum == 0)
    {
        if(flag == 0)
        {
            printf("0 %d %d",a[0],a[n-1]);
        }
       else
        {
            printf("0 0 0");  
        }
    }
    else
    {
        printf("%d %d %d",MaxSum,a[start],a[end]);
    }
} 
