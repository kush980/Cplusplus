#include<iostream>
using namespace std;

int dp[100][100];

int maxWays(int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0 and j==0)
            {
                dp[i][j] = 1;
            }
            else if(i==0)
            {
                dp[0][j] = 1;
            }
            else if(j==0)
            {
                dp[i][0] = 1;
            }
            else
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
            
        }
    }
    return dp[m-1][n-1];
}

int main()
{
    int m,n;
    cin>>m>>n;

    cout<<maxWays(m,n)<<endl;
}

