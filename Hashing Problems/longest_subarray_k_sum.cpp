#include<iostream>
#include<unordered_map>
using namespace std;

int lengthSubarrayKsum(int a[],int n,int k)
{
    unordered_map<int,int> m;
    int pre = 0;
    int len=0;
    for(int i=0;i<n;i++)
    {
        pre+=a[i];
       
        if(pre==k)
        len = max(len,i+1);

        if(m.find(pre-k)!=m.end())
        {
            len=max(len,i-m[pre-k]);
        }
        else
        {
            m[pre]=i;
        }
        
    }
    return len;
}

int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<lengthSubarrayKsum(a,n,k)<<endl;
}