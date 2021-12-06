#include <bits/stdc++.h>
using namespace std;

string lcs(string a, string b)
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
    string res = "";
    int i = n;
    int j = m;
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            res += a[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string a, b;
    cin >> a >> b;
    cout << lcs(a, b) << endl;
}