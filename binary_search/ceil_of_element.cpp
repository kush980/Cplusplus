#include <bits/stdc++.h>
using namespace std;

int ceil(vector<int> &nums, int target)
{
    int l = 0, r = nums.size() - 1;
    int mid;
    int res;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
        {
            res = nums[mid];
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return res;
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

    cout << ceil(nums, target) << endl;
}