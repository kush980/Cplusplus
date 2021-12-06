// Given a sorted array, find the element in the array which has minimum difference with the given number.

// If element is present then the min diff will be 0 i.e. with the element itself otherwise min of straction from floor or ceil of the element , ceil index will be l and floor index will be r after completion of binary search loop.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int t;
    cin >> t;

    int l = 0, r = n - 1;
    int mid;
    int res = 0;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (a[mid] == t)
        {
            res = a[mid];
            break;
        }
        else if (a[mid] > t)
            r = mid - 1;
        else
            l = mid + 1;
    }
    // if res !=0 , means t is not present so take floor and ceil
    // l will always be the index of ceil and r will always be the index of floor
    if (res == 0)
    {
        int tmp1 = abs(a[l] - t);
        int tmp2 = abs(a[r] - t);
        res = tmp1 < tmp2 ? a[l] : a[r];
        cout << res << endl;
    }
    else
        cout << res << endl;
}