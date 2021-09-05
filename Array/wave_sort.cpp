#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    //wave sorting 
    for(int i=0;i<n;i+=2)
    {
        //prev elements check
        if(i!=0 and a[i]<a[i-1])
        {
            swap(a[i],a[i-1]);
        }
        //next element check
        if(i!=(n-1) and a[i]<a[i+1])
        {
            swap(a[i],a[i+1]);
        }
   }
   for(int i=0;i<n;i++)
   {
       cout<<a[i]<<" ";
   }
}