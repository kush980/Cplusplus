#include<iostream>
#include<cstring>
using namespace std;

int dp[100];

int solve(int n)
{

    //look up
    if(dp[n]!=-1)
    {
        return dp[n];
    }

    //rec case
    if(n>2)
    {
        return dp[n] = solve(n-1) + (n-1)*solve(n-2);
    }
    else
    {
        dp[n] = n;
    }
}


int main()
{
    memset(dp,-1,sizeof dp);
    int n;
    cin>>n;
    cout<<solve(n)<<endl;

}