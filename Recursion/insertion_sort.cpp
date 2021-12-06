#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &vec, int temp)
{
    if (vec.size() == 0 || vec[vec.size() - 1] <= temp)
    {
        vec.push_back(temp);
        return;
    }
    int val = vec[vec.size() - 1];
    vec.pop_back();
    insert(vec, temp);
    vec.push_back(val);
}

void sort(vector<int> &vec)
{
    if (vec.size() == 1)
        return;
    int tmp = vec[vec.size() - 1];
    vec.pop_back();
    sort(vec);
    insert(vec, tmp);
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

    sort(vec);
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}