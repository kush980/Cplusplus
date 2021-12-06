#include <bits/stdc++.h>
using namespace std;

int subset_diff(vector<int> &arr, int n, int target)
{
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            if (j == 0)
                dp[i][j] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= target; j++) // If we are making subsets of 0 too , then only j is starting from 0
        {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n][target];
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

    int target;
    cin >> target;
    if ((target + sum) % 2 != 0)
    {
        cout << 0 << endl;
    }
    else
    {

        cout << subset_diff(arr, n, (target + sum) / 2) << endl;
    }
}