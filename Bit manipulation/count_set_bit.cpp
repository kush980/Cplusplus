#include<iostream>
using namespace std;

int countbit(int n)
{
    int ans=0;
    while(n>0)
    {
        ans+=(n&1);
        n=n>>1;
    }
    return ans;
}
int countbitfast(int n)
{
    int ans=0;
    while(n>0)
    {
        n=n&(n-1);
        ans++;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<countbit(n)<<endl;
    cout<<countbitfast(n)<<endl;
    cout<<__builtin_popcount(n)<<endl;
}