#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> white;
    vector<int> black;
    for(int i=0;i<n;i++)
    {
        int no;
        cin>>no;
        white.push_back(no);
    }
    for(int i=0;i<n;i++)
    {
        int no;
        cin>>no;
        black.push_back(no);
    }

    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans = ans + abs(white[i]-black[i]);
    }
    cout<<ans<<endl;

}