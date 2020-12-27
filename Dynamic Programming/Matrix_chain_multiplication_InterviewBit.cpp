#include<iostream>
#include<vector>
#include<climits>
#include<cstring>
using namespace std;

//the question is present in interview bit by the name matrix chain multiplication
//the time complexity - O(N^3)
//space complexity = O(N^2)

int solve(vector<int> &a )
{
    int dp[200][200];
    memset(dp,0,sizeof dp);

    int n = a.size() -1;
    for(int i=1;i<n;i++)
    {
        int r=0,c=i;
        while(c<n)
        {
            int val = INT_MAX;
            for(int pivot = r;pivot<c;pivot++)
            {
                val = min(val,dp[r][pivot]+dp[pivot+1][c]+a[r]*a[pivot+1]*a[c+1]);
            }
            dp[r][c] = val;
        }
    }
    return dp[0][n];
}