// FIND MAXIMUM ELEMENT IN AN BITONIC ARRAY:

// Problem statement:
// Given a bitonic array find the maximum value of the array. An array is said to be bitonic if it has an increasing sequence of integers followed immediately by a decreasing sequence of integers.

// Example:

// Input:
// 1 4 8 3 2

// Output:
// 8

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

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << peak_ele(v, n) << endl;
}