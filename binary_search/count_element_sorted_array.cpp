#include <bits/stdc++.h>
using namespace std;

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
    int first = -1, second = -1;
    int mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (arr[mid] == target)
        {
            first = mid;
            r = first - 1;
        }
        else if (arr[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }
    l = 0;
    r = n - 1;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (arr[mid] == target)
        {
            second = mid;
            l = second + 1;
        }
        else if (arr[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << second - first + 1 << endl;
}