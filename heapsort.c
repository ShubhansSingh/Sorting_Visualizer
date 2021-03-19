#include<stdio.h>
void adjust(int *a,int i,int n)
{
    int j,t;
    while(2*i<=n)
    {
        j=2*i;
        if(j+1<=n)
        {
            if(a[j+1]>a[j])
            j=j+1;
        }
        if(a[j]>a[i])
        {
            t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
        else
            break;
        i=j;
    }
}
void maxheapify(int *a,int n)
{
    int i;
    for(i=n/2;i>0;i--)
        adjust(a,i,n);
}
void heapsort(int *a,int n)
{
    int t,i;
    maxheapify(a,n);
    for(i=n;i>1;i--)
    {
        t=a[1];
        a[1]=a[i];
        a[i]=t;
        adjust(a,1,i-1);
    }
}
int main()
{
    int a[20]={0,7,1,5,100,50,89,47,2,65,15,48,54,1},i,n=13;
    heapsort(a,n);
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
        return 0;
}

