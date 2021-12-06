// Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.
// Example:
// for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4.

#include <bits/stdc++.h>
using namespace std;

int max_ways(vector<int> &coins, int sum, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0 & j > 0)
                dp[i][j] = 0;
            else if (i >= 0 & j == 0)
                dp[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coins[i - 1] <= j)
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int main()
{
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }
    int sum;
    cin >> sum;
    cout << max_ways(coins, sum, n) << endl;
}