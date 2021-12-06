// In this the size of array is not known

#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> &vec, int l, int r, int target)
{
    int mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2; // to avoid integer overflow in case of large l and r
        if (vec[mid] == target)
            return mid;
        else if (vec[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n); // but we wont take n as the size ,, as in the website q size will be unknown
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int target;
    cin >> target;

    int l = 0, r = 1;
    while (target > nums[r])
    {
        l = r;
        r = r * 2;
    }
    cout << bs(nums, l, r, target) << endl;
}