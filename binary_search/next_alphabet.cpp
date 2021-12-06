#include <bits/stdc++.h>
using namespace std;

char nextGreatestLetter(vector<char> &letters, char target)
{
    int l = 0;
    int r = letters.size() - 1;
    int mid;
    int res = -1;
    while (l <= r)
    {
        mid = (l + r) / 2;
        // if(letters[mid]==target)
        // {
        //     return mid==letters.size()-1?letters[0]:letters[mid+1];
        // }
        if (letters[mid] > target)
        {
            res = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    if (res == -1)
        return letters[0];
    return letters[res];
}

int main()
{
    int n;
    cin >> n;
    vector<char> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    char target;
    cin >> target;

    cout << nextGreatestLetter(vec, target) << endl;
}