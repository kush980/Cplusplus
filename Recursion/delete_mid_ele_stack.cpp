#include <bits/stdc++.h>
using namespace std;

// what we are basically doing is removing the top element and iterating till we get to the removing element then removing it and pushing the other elements again.

void solve(stack<int> &s, int k)
{
    if (k == 1)
    {
        s.pop();
        return;
    }
    int val = s.top();
    s.pop();
    solve(s, k - 1);
    s.push(val);
}

int main()
{
    int n;
    cin >> n;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        s.push(t);
    }
    int k = (n + 1) / 2;
    solve(s, k);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}