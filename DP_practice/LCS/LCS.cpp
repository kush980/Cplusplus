// Given two sequences, find the length of longest subsequence present in both of them.
//   A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.

// For example, “abc”,  “abg”, “bdf”, “aeg”,  ‘”acefg”, .. etc are subsequences of “abcdefg”.

#include <bits/stdc++.h>
using namespace std;

int LCS_rec(string &x, string &y, int n, int m)
{
    if (n == 0 || m == 0)
        return 0;
    if (x[n - 1] == y[m - 1])
        return 1 + LCS_rec(x, y, n - 1, m - 1);
    else
        return max(LCS_rec(x, y, n - 1, m), LCS_rec(x, y, n, m - 1));
}

int LCS_TOP_DOWN(string &x, string &y, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0 || m == 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (x[n - 1] == y[m - 1])
        return dp[n][m] = 1 + LCS_TOP_DOWN(x, y, n - 1, m - 1, dp);
    else
        return dp[n][m] = max(LCS_TOP_DOWN(x, y, n - 1, m, dp), LCS_TOP_DOWN(x, y, n, m - 1, dp));
}

int LCS_BU(string x, string y, int n, int m)
{
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i - 1] == y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int main()
{
    int n, m;
    string x, y;
    cin >> x >> y;
    n = x.length();
    m = y.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << LCS_rec(x, y, n, m) << endl;
    cout << LCS_TOP_DOWN(x, y, n, m, dp) << endl;
    cout << LCS_BU(x, y, n, m) << endl;
}