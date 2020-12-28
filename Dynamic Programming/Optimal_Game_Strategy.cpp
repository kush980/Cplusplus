#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

int dp[100][100];

int solve(int a[],int i,int j)
{
    //base case
    if(i>j)
    {
        return 0;
    }

    //lookup
    if(dp[i][j]!=0)
    {
        return dp[i][j];
    }

    //rec case
    int a1 = a[i]+min(solve(a,i+2,j),solve(a,i+1,j-1));
    int a2 = a[j]+min(solve(a,i,j-2),solve(a,i+1,j-1));
    int ans = max(a1,a2);
    return dp[i][j] = ans;
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
    memset(dp,0,sizeof dp);

    cout<<solve(a,0,n-1)<<endl;
}