#include<stdio.h>
void counting(int *a,int n,int d)
{
    int var,k=10;
    int i,j,t[10000],b[10000],c[1000];
    for(i=0;i<k;i++)
        c[i]=0;
    for(i=0;i<n;i++)
    {
        var=a[i];
        for(j=1;j<d;j++)
        {
            var/=10;
        }
        t[i]=var%10;
    }
    /*for(i=0;i<n;i++)
            printf("%d ",t[i]);
       printf("\n");*/
    for(i=0;i<n;i++)
        c[t[i]]++;
    for(i=1;i<=k;i++)
        c[i]+=c[i-1];
    for(i=n-1;i>=0;i--)
    {
        b[c[t[i]]-1]=a[i];
        c[t[i]]--;
    }
    /*for(i=0;i<n;i++)
            printf("%d ",b[i]);
            printf("\n");
    */for(i=0;i<n;i++)
        a[i]=b[i];
    return ;
}
void radix(int *a,int n,int d)
{
    int i;
        for(i=0;i<d;i++)
          counting(a,n,i+1);
        for(i=0;i<n;i++)
            printf("%d ",a[i]);
}
int main()
{
    int a[20]={525,250,879,426,156,348,569,789,101,124},n=10,d=3;
    radix(a,n,d);
}

