#include<iostream>
#include<cstring>
using namespace std;

int dp[100];

int solve(int n)
{
    //base case
    if(n==0 || n==1)
    {
        return 1;
    }

    //lookup
    if(dp[n]!=0)
    {
        return dp[n];
    }

    //rec case
    for(int i=1;i<=n;i++)
    {
        dp[n]+= solve(i-1) * solve(n-i);
    }
    return dp[n];
}


int main()
{
    int n;
    cin>>n;
    memset(dp,0,sizeof dp);
    cout<<solve(n)<<endl;
}