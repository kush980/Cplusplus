// Given a value V, if we want to make change for V cents, and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins, what is the minimum number of coins to make the change?
// Example:

// Input: coins[] = {25, 10, 5}, V = 30
// Output: Minimum 2 coins required
// We can use one coin of 25 cents and one of 5 cents

#include <bits/stdc++.h>
using namespace std;

int min_coins(vector<int> &coins, int sum, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0 & j > 0)
                dp[i][j] = INT_MAX - 1;
            else if (i >= 0 & j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coins[i - 1] <= j)
                dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    if (dp[n][sum] != INT_MAX - 1)
        return dp[n][sum];
    else
        return -1;
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
    cout << min_coins(coins, sum, n) << endl;
}