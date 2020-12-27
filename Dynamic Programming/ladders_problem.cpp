#include<iostream>
using namespace std;


int laddersProblem(int n,int k,int dp[])
{
    //base case
    if(n==0)
    {
        return 1;
    }

    //lookup
    if(dp[n]!=0)
    {
        return dp[n];
    }

    //rec case
    int ways=0;
    for(int i=1;i<=k;i++)
    {
        if(n-i>=0)
        {
            ways+=laddersProblem(n-i,k,dp);
        }
    }
    return dp[n] = ways;

}

int LadderProblemBU(int n,int k)
{
    int dp[100] = {0};

    dp[0] = 1;

    for(int i=1;i<=n;i++)
    {
        dp[i] = 0;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                dp[i]+=dp[i-j]; 
            }
        }
    }
    return dp[n];
}

int ladders_Optimised(int n,int k)
{
    int dp[100] = {0};

    dp[0] = dp[1] = 1;
    for(int i=2;i<=k;i++)
    {
        dp[i]=2*dp[i-1];
    }
    for(int i=k+1;i<=n;i++)
    {
        dp[i]= 2*dp[i-1] - dp[i-k-1];
    }

    for(int i=0;i<n;i++)
    {
        cout<<dp[i]<<" ";
    }

    return dp[n];
}

int main()
{
    int n,k;
    cin>>n>>k;

    int dp[100] = {0};
    cout<<"No. of ways are : "<<ladders_Optimised(n,k)<<endl;
}