#include <bits/stdc++.h>
using namespace std;

vector<int> LIS(vector<int> &a, int n)
{
    vector<int> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }
    }
    // return *max_element(dp.begin(), dp.end());
    // int i = lis(a, n);
    vector<int> res;
    int maxi = INT_MIN;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            index = i;
        }
    }
    res.push_back(a[index]);
    for (int i = index; i > 0; i--)
    {
        if (dp[i] + 1 == dp[index] && a[i] < a[index])
        {
            res.push_back(a[i]);
            index = i;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> ans;
    ans = LIS(a, n);
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
}