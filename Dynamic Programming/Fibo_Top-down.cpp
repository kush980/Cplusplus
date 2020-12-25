#include<iostream>
using namespace std;

int fibo(int n,int dp[])
{
    //base case
    if(n==0 ||n==1)
    {
        return n;
    }

    //recursive case with look up
    //top down approach - recursion + memoisation
    if(dp[n]!=0)
    {
        return dp[n];
    }

    int ans;
    ans = fibo(n-1,dp) + fibo(n-2,dp);
    return dp[n] = ans;
}

int main()
{
    int n;
    cin>>n;

    int dp[100]={0};

    cout<<fibo(n,dp)<<endl;
}