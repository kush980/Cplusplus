#include<iostream>
using namespace std;

int first_occurence(int ar[],int n,int k)
{
    int s=0;
    int e=n-1;
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(ar[mid]==k)
        {
            ans=mid;
            e=mid-1;
        }
        else if(ar[mid]>k)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return ans;
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
    int k;
    cin>>k;
    cout<<first_occurence(a,n,k)<<endl;
    return 0;
}