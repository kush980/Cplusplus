#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

//in this method "i" denotes the length and dp[i] denotes the value of the element
// element will only be stored if its less than greater than previous element and less then next one
//such that we take out the optimal solution
//time complexity - O(NlogN)


int LIS(int a[],int n)
{
    int dp[n+1];
    dp[0] = INT_MIN;

    for(int i=1;i<=n;i++)
    {
        dp[i] = INT_MAX;
    }

    for(int i=0;i<n;i++)
    {
        int length = upper_bound(dp,dp+n+1,a[i])-dp;
        if(dp[length-1]<a[i] && a[i]<dp[length])
        dp[length]= a[i];
    }

    int lis;
    for(int i=1;i<=n;i++)
    {
        if(dp[i]!=INT_MAX)
        lis=i;
    }

    return lis;
}


int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cout<<LIS(a,n)<<endl;
}