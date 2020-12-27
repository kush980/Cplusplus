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


int main()
{
    int n,k;
    cin>>n>>k;

    int dp[100] = {0};
    cout<<"No. of ways are : "<<laddersProblem(n,k,dp)<<endl;
}