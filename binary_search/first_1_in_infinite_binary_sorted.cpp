// Given an infinite sorted array consisting 0s and 1s. The problem is to find the index of first ‘1’ in that array. As the array is infinite, therefore it is guaranteed that number ‘1’ will be present in the array.

// Example:

// Input : arr[] = {0, 0, 1, 1, 1, 1}
// Output : 2

#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> &vec, int l, int r, int target)
{
    int res = -1;
    int mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2; // to avoid integer overflow in case of large l and r
        if (vec[mid] == target)
        {
            res = mid;
            r = mid - 1;
        }
        else if (vec[mid] > target)
            r = mid - 1;
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

    int target = 1;
    int l = 0, r = 1;
    while (target > nums[r])
    {
        l = r;
        r = r * 2;
    }
    cout << bs(nums, l, r, target) << endl;
}