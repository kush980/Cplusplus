#include<iostream>
#include<unordered_set>
using namespace std;

bool checksum(int a[],int n)
{
    unordered_set<int> s;
    int pre = 0;

    for(int i=0;i<n;i++)
    {
        pre+=a[i];
        //check if the sum is already present in the set
        if(pre==0 || s.find(pre)!=s.end())
        {
            return true;
        }
        s.insert(pre);
    }
    return false;
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

    if(checksum(a,n))
    {
        cout<<"Subarray sum is zero"<<endl;
    }
    else
    {
        cout<<"No Subarray with sum zero"<<endl;
    }
    
}