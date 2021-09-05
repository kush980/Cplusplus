//have to make n-cell using 3 different option 
//either double them , increment by 1 or decrement by 1
//each has its own cost , find the minimum cost to make the n cells

#include<iostream>
using namespace std;

int solve(int n,int x,int y,int z)
{
    int dp[100];
    dp[0] = 0;
    dp[1] = 0;

    for(int i=2;i<=n;i++)
    {
        if(i%2==0)
        {
            dp[i] = min(dp[i/2]+x,dp[i-1]+y);
        }
        else
        {
            dp[i] = min(dp[i-1]+y,dp[i/2]+x+z);
        }
        
    }
    return dp[n];
}

int main()
{
    int n,x,y,z;
    cin>>n>>x>>y>>z;

    cout<<solve(n,x,y,z)<<endl;
}