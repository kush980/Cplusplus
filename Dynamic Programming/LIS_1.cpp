#include<iostream>
using namespace std;

int LIS_DP(int a[],int n,int dp[])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i])
            dp[i] = max(dp[i],dp[j]+1);
        }
    }
    int lis =0;
    for(int i=0;i<n;i++)
    {
        cout<<dp[i]<<" ";
        lis = max(lis,dp[i]);
    }
    cout<<endl;
    return lis;
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

    int dp[100] = {1};

    cout<<LIS_DP(a,n,dp)<<endl;
}