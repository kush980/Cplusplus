#include <bits/stdc++.h>
using namespace std;

int U_knapsack(vector<int> &wt, vector<int> &val, int n, int W, vector<vector<int>> &dp)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (dp[n][W] != -1)
    {
        return dp[n][W];
    }
    if (wt[n - 1] <= W)
    {
        return dp[n][W] = max(val[n - 1] + U_knapsack(wt, val, n, W - wt[n - 1], dp), U_knapsack(wt, val, n - 1, W, dp));
    }
    else if (wt[n - 1] > W)
    {
        return dp[n][W] = U_knapsack(wt, val, n - 1, W, dp);
    }
    return dp[n][W];
}

int BU_knapsack(vector<int> &wt, vector<int> &val, int N, int W)
{
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] <= j)
                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[N][W];
}

int main()
{
    int n;
    cin >> n;
    vector<int> wt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }
    vector<int> val(n);
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }
    int W;
    cin >> W;
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    // cout << U_knapsack(wt, val, n, W, dp) << endl;
    cout << BU_knapsack(wt, val, n, W) << endl;
}