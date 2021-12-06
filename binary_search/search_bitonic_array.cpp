// FIND AN ELEMENT IN BITONIC ARRAY:

// Given a bitonic sequence of n distinct elements, write a program to find a given element x in the bitonic sequence in O(log n) time. A Bitonic Sequence is a sequence of numbers which is first strictly increasing then after a point strictly decreasing.

// Examples:

// Input :  arr[] = {-3, 9, 8, 20, 17, 5, 1};
//          key = 20
#include <bits/stdc++.h>
using namespace std;

int peak_ele(vector<int> &v, int n)
{
    int l = 0, r = n - 1, mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (mid > 0 && mid < n - 1)
        {
            if (v[mid] > v[mid - 1] && v[mid] > v[mid + 1])
                return mid;
            else if (v[mid] < v[mid - 1])
                r = mid - 1;
            else
                l = mid + 1;
        }
        else if (mid == 0)
        {
            if (v[mid] > v[mid + 1])
                return mid;
            else
                return mid + 1;
        }
        else
        {
            if (v[mid] > v[mid - 1])
                return mid;
            else
                return mid - 1;
        }
    }
    return -1;
}

int bs_asc(vector<int> v, int n, int target)
{
    int l = 0, r = n - 1, mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (v[mid] == target)
            return mid;
        else if (v[mid] > target)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int bs_dsc(vector<int> v, int i, int n, int target)
{
    int l = i, r = n - 1, mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (v[mid] == target)
            return mid;
        else if (v[mid] > target)
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
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int target;
    cin >> target;
    int idx = peak_ele(v, n);
    int asc = bs_asc(v, idx - 1, target);
    int dsc = bs_dsc(v, idx, n, target);

    if (asc == -1 and dsc == -1)
        cout << -1 << endl;
    else
        cout << max(asc, dsc) << endl;
}