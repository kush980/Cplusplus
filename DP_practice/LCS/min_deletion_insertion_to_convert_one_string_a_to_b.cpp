#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    int dp[n + 1][m + 1];
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
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int minOperations(string str1, string str2)
{
    int common = lcs(str1, str2);
    int deletion = str1.length() - common;
    int insertion = str2.length() - common;
    int res = insertion + deletion;
    return res;
    // Your code goes here
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << minOperations(s1, s2) << endl;
}