#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> &arr, int l, int r, int target)
{
    int mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
            l = mid + 1;
        else
            r = mid - 1;
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
    int l = 0;
    int r = n - 1;
    cout << bs(arr, l, r, target) << endl;
}