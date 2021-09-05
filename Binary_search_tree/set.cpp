#include<iostream>
#include<set>
using namespace std;

int main()
{
    int a[] = {10,3,4,10,5,12,22,1};
    int n = sizeof(a)/sizeof(int);

    set<int> s;
    for(int i=0;i<n;i++)
    {
        s.insert(a[i]);
    }

    s.erase(22);

    for(auto x:s)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    

    return 0;
}