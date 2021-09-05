#include<iostream>
using namespace std;

int storeocc(int *a,int i,int n,int key,int *out,int j)
{
    if(i==n)
    return j;
    if(a[i]==key)
    {
        out[j]=i;
       return storeocc(a,i+1,n,key,out,j+1);
    }
    return storeocc(a,i+1,n,key,out,j);
}

void allocc(int *a,int i,int n,int key)
{
    if(i==n)
    return ;
    if(a[i]==key)
    cout<<i<<",";
    allocc(a,i+1,n,key);
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
    allocc(a,0,n,key);
    int output[100];
    int cnt=storeocc(a,0,n,key,output,0);
    cout<<endl;
    for(int k=0;k<cnt;k++)
    cout<<output[k]<<" ";
}