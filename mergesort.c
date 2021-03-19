#include<stdio.h>
void merge(int *a,int low,int mid,int high)
{
    int i=low,j=mid+1,k=0;
    int c[1000],s;
    s=high-low+1;
    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
            c[k++]=a[i++];
        else
            c[k++]=a[j++];
    }
    while(i<=mid)
        c[k++]=a[i++];
    while(j<=high)
        c[k++]=a[j++];
for(i=0;i<k;i++)
    a[low+i]=c[i];
    return;
    }
void mergesort(int *a,int low,int high)
{
    if(low<high)
    {
        int mid;
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
    return;
}
int main()
{
    int a[100]={50,10,30,20,5,69,15,78,100,105,0,9,15};
    int i,n=13;
    mergesort(a,0,n-1);
    printf("Array = ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}

