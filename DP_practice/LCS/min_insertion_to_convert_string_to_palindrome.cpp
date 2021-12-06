// Minimum number of insertions to make a string palindrome
// Given a string, find the minimum number of characters to be inserted to form Palindrome string out of given string

// Examples:
// ab: Number of insertions required is 1. bab
// aa: Number of insertions required is 0. aa

#include <bits/stdc++.h>
using namespace std;

int lcs(string s, string s2)
{
    int n = s.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
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
            if (s[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int min_insertion(string s)
{
    string s2 = s;
    reverse(s2.begin(), s2.end());
    int l = lcs(s, s2);
    return s.length() - l;
}

int main()
{
    string s;
    cin >> s;
    cout << min_insertion(s) << endl;
}