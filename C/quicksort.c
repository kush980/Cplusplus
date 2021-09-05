#include<stdio.h>

int partition(int *a,int s,int e)
{
    int i=s-1;
    int j=s;
    int pivot=a[e];


    for(;j<e;j++)
    {
        if(a[j]<=pivot)
        {
            i=i+1;
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    int temp = a[i+1];
    a[i+1] = a[e];
    a[e] = temp;
    return i+1;
}

void quicksort(int *a,int s,int e)
{
    if(s>=e)
    return;
    int p=partition(a,s,e);
    quicksort(a,s,p-1);

    quicksort(a,p+1,e);

}

int main()
{
    int n;
    printf("Enter the size of Array: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements of Array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n);
    printf("Sorted Array: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}