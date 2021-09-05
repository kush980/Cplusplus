#include<iostream>
#include<vector>
using namespace std;

void isprime(int n)
{
    int cnt;
    vector<pair<int,int> > factors;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            cnt=0;
            while(n%i==0)
            {
                cnt++;
                n=n/i;
            }
            factors.push_back(make_pair(i,cnt));
        }
    }
    if(n!=1)
    {
        factors.push_back(make_pair(n,1));
    }
    for(auto a:factors)
    {
        cout<<a.first<<"^"<<a.second<<endl;
    }
    return;
}

int main()
{
    int n;
    cin>>n;
    isprime(n);
    return 0;
}