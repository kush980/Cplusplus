#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &s, int temp)
{
    if (s.empty() || s.top() <= temp)
    {
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s, temp);
    s.push(val);
}

void sort(stack<int> &s)
{
    if (s.size() == 1)
        return;
    int val = s.top();
    s.pop();
    sort(s);
    insert(s, val);
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
    sort(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}