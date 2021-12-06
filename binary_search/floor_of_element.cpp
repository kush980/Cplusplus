#include <bits/stdc++.h>
using namespace std;

int floor(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size() - 1;
    int res = 0;
    int mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            r = mid - 1;
        else
        {
            res = nums[mid];
            l = mid + 1;
        }
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

    cout << floor(nums, target) << endl;
}