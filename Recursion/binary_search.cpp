#include<iostream>
using namespace std;

int binary(int a[],int key,int s,int e)
{
    //  s=0;
    //  e=sizeof(a)/sizeof(int)-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(a[mid]==key)
        return mid;
        if(a[mid]>key)
        return binary(a,key,s,mid-1);
        if(a[mid]<key)
        return binary(a,key,mid+1,e);
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int key;
    cin>>key;
    int s=0;
    int e=n-1;
    cout<<binary(a,key,s,e)<<endl;
}