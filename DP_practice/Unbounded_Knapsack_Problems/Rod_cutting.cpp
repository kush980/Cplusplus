#include <bits/stdc++.h>
using namespace std;

int cutting(vector<int> &len, vector<int> &price, int n, int N)
{
    vector<vector<int>> dp(n + 1, vector<int>(N + 1, -1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (len[i - 1] <= j)
                dp[i][j] = max(price[i - 1] + dp[i][j - len[i - 1]], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][N];
}

int main()
{
    int n;
    cin >> n;
    vector<int> len(n);
    for (int i = 0; i < n; i++)
    {
        len[i] = i + 1;
    }
    vector<int> price(n);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }
    int N;
    cin >> N;
    vector<vector<int>> dp(n + 1, vector<int>(N + 1, -1));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= N; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    cout << cutting(len, price, n, N) << endl;
}