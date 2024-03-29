#include<iostream>
using namespace std;

int dp[100][100];
int cost[100][100];

int minCostPath(int r,int c)
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            //base case
            if(i==0 and j==0)
            {
                dp[i][j] = cost[0][0];
            }
            else if(i==0)
            {
                dp[i][j] = dp[0][j-1] + cost[0][j];
            }
            else if(j==0)
            {
                dp[i][j] = dp[i-1][0] + cost[i][0];
            }
            else
            {
                dp[i][j] = min(dp[i-1][j],dp[j][i-1]) + cost[i][j];
            }
            
        }
    }
    return dp[r][c];
}

