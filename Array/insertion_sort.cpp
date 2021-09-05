#include<iostream>
using namespace std;
void insertion_sort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
    int cur=a[i];
    int j=i-1;
    while(j>=0 and a[j]>cur)
    {
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=cur;
    }
}
int main()
{
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    insertion_sort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<",";
    }
    return 0;
}