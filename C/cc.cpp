#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, i, smallest, biggest, ans;
    cin >> t;
    while(t--)
    {
        smallest = 999999999;
        biggest = 0;
        cin >> n;
        int arr[n];
        for(i=0;i<n;i++)
        {
            cin >> arr[i];
            biggest = max(biggest, arr[i]);
            smallest = min(smallest, arr[i]);
        }
        ans = 2*(biggest - smallest);
        cout << ans << "\n";
    }
    return 0;
}