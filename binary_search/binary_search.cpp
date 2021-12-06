#include <bits/stdc++.h>
using namespace std;

int bs(vector<int> &vec, int n, int target)
{
    int l = 0;
    int r = n - 1;
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
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    int l = 0, r = n - 1;
    int target;
    cin >> target;

    cout << bs(vec, n, target) << endl;
}