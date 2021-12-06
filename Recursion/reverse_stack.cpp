#include <bits/stdc++.h>
using namespace std;

// in reverse function we are leaving just the last element and calling insert function with last ele and 2nd last ele , in insert it will pop all ele of stack and then put the ele passed through  func and the remaining elements which were present in the stack. thus the element passed will be at the bottom , thus the stack is reversed.

void insert(stack<int> &s, int ele)
{
    if (s.size() == 0)
    {
        s.push(ele);
        return;
    }
    int val = s.top();
    s.pop();
    // s.push(val);
    insert(s, ele);
    s.push(val);
}

void reverse(stack<int> &s)
{
    if (s.size() == 1)
    {
        return;
    }
    int tmp = s.top();
    s.pop();
    reverse(s);
    insert(s, tmp);
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

    reverse(s);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}