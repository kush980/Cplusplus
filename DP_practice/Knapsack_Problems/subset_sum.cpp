#include <bits/stdc++.h>
using namespace std;

bool subset_sum(vector<int> &nums, int target, int n)
{
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            if (j == 0)
                dp[i][j] = true;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (nums[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][target];
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int target;
    cin >> target;
    if (subset_sum(nums, target, n))
        cout << "TRUE" << endl;
    else
        cout << "FALSE" << endl;
    // cout << subset_sum(nums, target, n) << endl;
}