#include<stdio.h>

void merge(int *a,int s,int e)
{
    int mid=(s+e)/2;
    int i=s;
    int j=mid+1;
    int k=s;

    int temp[100];
    while(i<=mid && j<=e)
    {
        if(a[i]<a[j])
        temp[k++]=a[i++];
        else
        {
            temp[k++]=a[j++];
        }
    }
    while(i<=mid)
    temp[k++]=a[i++];
    while (j<=e)
    {
        temp[k++]=a[j++];
    }
    for(int i=s;i<=e;i++)
    {
        a[i]=temp[i];
    }
    
}

void mergesort(int a[],int s,int e)
{
    if(s>=e)
    return;
    int mid=(s+e)/2;
    mergesort(a,s,mid);
    mergesort(a,mid+1,e);

    merge(a,s,e);
}

int main()
{
    int n;
    printf("Enter the size of Array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements in array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    //printf("\n");
    mergesort(a,0,n);
    printf("Sorted Array: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}