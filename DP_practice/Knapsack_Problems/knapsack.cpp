#include <bits/stdc++.h>
using namespace std;

int knapsack(int W, vector<int> &wt, vector<int> &val, int n, vector<vector<int>> dp)
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
        return dp[n][W] = max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1, dp), knapsack(W, wt, val, n - 1, dp));
    }
    else if (wt[n - 1] > W)
    {
        return dp[n][W] = knapsack(W, wt, val, n - 1, dp);
    }
    return dp[n][W];
}

int knapsack_BU(int W, vector<int> &wt, vector<int> &val, int n)
{
    vector<vector<int>> t(n + 1, vector<int>(W + 1, -1));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < W + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < W + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            }
            else if (wt[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][W];
}

int main()
{
    int n;
    cin >> n;
    vector<int> wt(n);
    vector<int> val(n);
    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> val[i];
    }
    int W;
    cin >> W;

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
    cout << knapsack(W, wt, val, n, dp) << endl;
    cout << knapsack_BU(W, wt, val, n) << endl;
}