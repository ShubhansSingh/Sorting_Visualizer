#include<stdio.h>
#include<stdlib.h>
void quicksort(int *a,int low,int high)
{
    if(low<high)
    {
        int j;
        j=partition(a,low,high);
        quicksort(a,low,j-1);
        quicksort(a,j+1,high);
    }
}
int partition(int *a,int low,int high)
{
    int t,i,j,pivot,r;
    r=rand()%(high-low+1);
    i=low;
    j=high+1;
    t=a[low];
    a[low]=a[low+r];
    a[low+r]=t;
    pivot=a[low];
    do{
    do{
        i++;
    }while(a[i]<pivot);
    do{
        j--;
    }while(a[j]>pivot);
    if(i<j)
    {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
    }while(i<j);
    t=a[j];
    a[j]=a[low];
    a[low]=t;
    return j;
}
int main()
{
    int a[15]={119,248,58,15,223,166,77,11,1000},n=8,i;
    quicksort(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
