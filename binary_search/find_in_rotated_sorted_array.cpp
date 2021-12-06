#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    int mid;
    int n = nums.size();
    int l = 0, r = nums.size() - 1;
    int start;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;
        if (nums[prev] > nums[mid] && nums[next] > nums[mid])
        {
            start = mid;
            break;
        }
        else if (nums[mid] <= nums[r])
            r = mid - 1;
        else
            l = mid + 1;
    }
    if (start == nums.size())
        start = 0;
    if (target >= nums[start] && target <= nums[n - 1])
    {
        l = start;
        r = n - 1;
    }
    else
    {
        l = 0;
        r = start - 1;
    }
    cout << l << " " << r << endl;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
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
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    cout << search(arr, target) << endl;
}