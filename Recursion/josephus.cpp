#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &vec, int k, int index)
{
    if (vec.size() == 1)
    {
        return vec[0];
    }
    index = ((index + k) % vec.size());
    vec.erase(vec.begin() + index);
    return solve(vec, k, index);
}

int safePos(int n, int k)
{
    // code here
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        vec[i] = i + 1;
    }
    // int index =0;
    return solve(vec, k - 1, 0);
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    cout << safePos(n, k) << endl;
}