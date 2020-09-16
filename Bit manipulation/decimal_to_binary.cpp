#include<iostream>
using namespace std;

int decimaltobinary(int n)
{
    int ans=0;
    int p=1;
    while(n>0)
    {
        int bit=(n&1);
        ans+=p*bit;
        p=p*10;
        n=n>>1;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    cout<<decimaltobinary(n)<<endl;
    return 0;
}