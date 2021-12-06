#include <bits/stdc++.h>
using namespace std;

bool subset_sum(vector<int> &nums, int sum, int n)
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
            if (nums[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

bool equal_sum(vector<int> &nums, int sum, int n)
{
    if (sum % 2 != 0)
    {
        return false;
    }
    return subset_sum(nums, sum / 2, n);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }

    if (equal_sum(nums, sum, n))
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }
}