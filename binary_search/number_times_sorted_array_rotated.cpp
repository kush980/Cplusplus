#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &arr, int n)
{
    int l = 0, r = n - 1;
    int mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;
        if (arr[prev] >= arr[mid] && arr[next] >= arr[mid])
            return mid;
        else if (arr[mid] <= arr[r])
            r = mid - 1;
        else
            l = mid + 1;
    }
    return 0;
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

    cout << search(arr, n) << endl;
}