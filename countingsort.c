#include<stdio.h>
void counting(int *a,int n,int k)
{
    int i,b[10000],c[1000];
    for(i=0;i<=k;i++)
        c[i]=0;
    for(i=0;i<n;i++)
        c[a[i]]++;
    for(i=1;i<=k;i++)
        c[i]+=c[i-1];
    for(i=0;i<n;i++)
    {
        b[c[a[i]]-1]=a[i];
        c[a[i]]--;
    }
    for(i=0;i<n;i++)
        printf("%d ",b[i]);
    return ;
}
int main()
{
    int a[15]={1,0,3,2,6,5,6,2,4,4,1,3,2,6,6},n=15,k=6;
    counting(a,n,k);
    return 0;
}

