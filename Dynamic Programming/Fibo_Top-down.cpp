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

//bottom up approach    //time - O(N)   space-O(N)
int fiBU(int n)
{
    int dp[100]={0};
    dp[1] = 1;

    for(int i=2;i<n;i++)
    {
        dp[i] = dp[n-1] + dp[n-2];
    }

    return dp[n];
}

//bottom up with space optimisation         //space - O(1)
int fibspace(int n)
{
    if(n==0 or n==1)
    {
        return n;
    }

    int a = 0;
    int b=1;
    int c;

    for(int i=2;i<=n;i++)
    {
        c = a+b;
        a=b;
        b=c;
    }

    return c;
}

int main()
{
    int n;
    cin>>n;

    int dp[100]={0};

    cout<<fibspace(n)<<endl;
}