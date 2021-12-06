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

int minimumNumberOfDeletions(string S)
{
    string s2 = S;
    reverse(s2.begin(), s2.end());
    int pal = lcs(S, s2);
    int res = S.length() - pal;
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << minimumNumberOfDeletions(s) << endl;
}
