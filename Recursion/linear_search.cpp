#include<iostream>
using namespace std;

int firstocc(int *a,int n,int key)
{
    if(n==0)
    return -1;

    if(a[0]==key)
    return 0;

    int i=firstocc(a+1,n-1,key);
    if(i==-1)
    return -1;

    return i+1;
}

int linearsearch(int *a,int i,int n,int key)
{
    if(i==n)
    return -1;

    if(a[i]==key)
    return i;

    return linearsearch(a,i+1,n,key);
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int key;
    cin>>key;
    int i=0;
    cout<<linearsearch(a,i,n,key)<<endl;
    cout<<firstocc(a,n,key)<<endl;
}