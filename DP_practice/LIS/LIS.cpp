#include <bits/stdc++.h>
using namespace std;

int lis(vector<int> &a, int n)
{
    vector<int> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j])
                dp[i] = dp[j] + 1;
        }
    }
    return *max_element(dp.begin(), dp.end());
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
    cout << lis(a, n) << endl;
}