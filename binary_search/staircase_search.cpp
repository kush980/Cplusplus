// SEARCH IN A ROW WISE AND COLUMN WISE SORTED MATRIX:

// Given an n x n matrix and a number x, find the position of x in the matrix if it is present in it. Otherwise, print “Not Found”. In the given matrix, every row and column is sorted in increasing order. The designed algorithm should have linear time complexity.
// Example :

// Input : mat[4][4] = { {10, 20, 30, 40},
//                       {15, 25, 35, 45},
//                       {27, 29, 37, 48},
//                       {32, 33, 39, 50}};
//               x = 29

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> vec(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> vec[i][j];
        }
    }
    int key;
    cin >> key;
    int i = 0, j = m - 1;
    bool flag = false;
    while (i < n && j > 0)
    {
        if (vec[i][j] == key)
        {
            flag = true;
            break;
        }
        else if (vec[i][j] > key)
            j--;
        else
            i++;
    }
    if (flag)
        cout << "Element found at (" << i << "," << j << ")" << endl;
    else
        cout << "Element was not present" << endl;
}