#include<stdio.h>  
#include<stdlib.h>  
      
int *FindMaxCrossSubarray(int A[],int low,int mid,int high)  
{  
    int lsum = -10000;  
    int rsum = -10000;  
    int sum = 0;  
    int i;  
    int *res;  
    res = (int *)malloc(sizeof(int)*3);  
    for(i = mid;i >= low ;i--)  
    {  
        sum += A[i];  
        if (sum > lsum)  
        {  
            lsum = sum;  
            res[0] = i;  
        }  
	}  
    sum = 0;  
    for(i = mid+1;i<=high;i++)  
    {  
        sum += A[i];  
        if(sum > rsum)  
        {  
            rsum = sum;  
            res[1] = i;  
        }  
    }  
    res[2] = (lsum+rsum);  
    return res;  
}  
              
int *FindMaximumSubarray(int A[],int low,int high)  
{  
    int *res;  
    int mid;  
    int *resL,*resR,*resC;  
    res = (int *)malloc(sizeof(int)*3);  
    resL = (int *)malloc(sizeof(int)*3);  
    resR = (int *)malloc(sizeof(int)*3);  
    resC = (int *)malloc(sizeof(int)*3);  
    if(high == low)  
    {  
        res[0] = low;  
        res[1] = high;  
        res[2] = A[low];  
        return res;  
    }  
    else  
    {  
        mid = (int)((low+high)/2);  
        resL = FindMaximumSubarray(A,low,mid);  
        resR = FindMaximumSubarray(A,mid+1,high);  
        resC = FindMaxCrossSubarray(A,low,mid,high);  
          
        if(resL[2] >= resR[2]  && resL[2] >= resC[2])  
            return resL;  
        else if(resR[2] >= resL[2] && resR[2] >= resC[2])  
            return resR;  
        else  
            return resC;  
    }  
}  
      
int main()  
{  
    int i;  
    int *result;  
    int A[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};  
    result = FindMaximumSubarray(A,0,15);  
    for(i=0;i<3;i++)  
    {  
        printf("%d ",result[i]);  
    }  
    printf("\n");  
    return 0;  
}  
