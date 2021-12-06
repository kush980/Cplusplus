#include <bits/stdc++.h>
using namespace std;

int min_subset_diff(vector<int> &arr, int n, int sum)
{
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0)
                dp[i][j] = true;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    int ans = INT_MAX;
    for (int i = sum / 2; i >= 0; i--)
    {
        if (dp[n][i] == true)
        {
            ans = min(ans, (sum - 2 * i));
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    cout << min_subset_diff(arr, n, sum) << endl;
}