#include<iostream>
using namespace std;

int profit(int n,int c,int*wt,int *prices)
{
    //base case
    if(n==0 || c==0)
    {
        return 0;
    }

    //rec case
    int ans=0;
    int inc=0,exc=0;
    if(wt[n-1]<=c)
    {
        inc=prices[n-1]+profit(n-1,c-wt[n-1],wt,prices);
    }
    exc=profit(n-1,c,wt,prices);
    ans=max(inc,exc);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int prices[n],wt[n];
    for(int i=0;i<n;i++)
    {
        cin>>wt[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>prices[i];
    }
    int c;
    cin>>c;
    cout<<profit(n,c,wt,prices);
}