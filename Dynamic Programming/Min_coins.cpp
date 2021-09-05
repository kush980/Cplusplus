#include<iostream>
#include<climits>
using namespace std;

int minCoinsTD(int n,int coins[],int t,int dp[])
{
    //base case
    if(n==0)
    {
        return 0;
    }
    //look up
    if(dp[n]!=0)
    {
        return dp[n];
    }
    //rec case
    int ans = INT_MAX;
    for(int i=0;i<t;i++)
    {
        
        if(n-coins[i]>=0)
        {
            int subprob = minCoinsTD(n-coins[i],coins,t,dp);
            ans = min(ans,subprob+1);
        }
    }
    return dp[n]=ans;
}

int minCoinsBU(int n,int coins[],int t)
{
    int dp[100] = {0};


    for(int N=1;N<=n;N++)
    {
        dp[N] = INT_MAX;
        for(int i=0;i<t;i++)
        {
            if(N-coins[i]>=0)
            {
                int subprob = dp[N-coins[i]];
                dp[N] = min(dp[N],subprob+1);
            }
        }
    }
    return dp[n];
}



int main()
{
    int n;
    cin>>n;
    int coins[] = {1,7,10};
    int t = sizeof(coins)/sizeof(int);
    int dp[100] = {0};

    cout<<minCoinsTD(n,coins,t,dp)<<endl;
    cout<<minCoinsBU(n,coins,t)<<endl;
}