//Check if string a is a subsequence of string b
// a = AXY
// b = ACXBYZ
// Output = True

#include <bits/stdc++.h>
using namespace std;

int longest_common_subsequence(string a, string b)
{
    int n = a.length();
    int m = b.length();
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
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int main()
{
    string a, b;
    cin >> a >> b;
    int lcs = longest_common_subsequence(a, b);
    if (lcs == a.length())
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;
}