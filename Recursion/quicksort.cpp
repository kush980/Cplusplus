#include<iostream>
using namespace std;

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
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[e]);
    return i+1;
}

void quicksort(int *a,int s,int e)
{
    if(s>=e)
    return;
    int p=partition(a,s,e);

    //sorting on smaller part
    quicksort(a,s,p-1);

    //sorting on larger part
    quicksort(a,p+1,e);

}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];

    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}