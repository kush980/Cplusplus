// ALLOCATE MINIMUM NUMBER OF PAGES:

// Given number of pages in n different books and m students. The books are arranged in ascending order of number of pages. Every student is assigned to read some consecutive books. The task is to assign books in such a way that the maximum number of pages assigned to a student is minimum.

// Example :

// Input : pages[] = {12, 34, 67, 90}
//         m = 2
// Output : 113
// Explanation:
// There are 2 number of students. Books can be distributed
// in following fashion :
//   1) [12] and [34, 67, 90]
//       Max number of pages is allocated to student
//       2 with 34 + 67 + 90 = 191 pages
//   2) [12, 34] and [67, 90]
//       Max number of pages is allocated to student
//       2 with 67 + 90 = 157 pages
//   3) [12, 34, 67] and [90]
//       Max number of pages is allocated to student
//       1 with 12 + 34 + 67 = 113 pages

// Of the 3 cases, Option 3 has the minimum pages = 113.

#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int> &v, int n, int k, int mid)
{
    if (k > n)
        return false;
    int student = 1;
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        if (sum > mid)
        {
            student++;
            sum = v[i];
        }
        // cout << mid << " " << student << endl;
        if (student > k)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    int r = 0;
    int l = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        r += v[i];
        l = max(l, v[i]);
    }
    // cout << l << " " << r << endl;
    int k;
    cin >> k;
    int mid = 0, res = 0;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (isValid(v, n, k, mid))
        {
            // cout << mid << endl;
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << res << endl;
}