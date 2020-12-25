#include<iostream>
#include<climits>
using namespace std;

//Top down approach
int minstepTD(int n,int dp[])
{
    //base case
    if(n==1)
    {
        return 0;
    }

    //rec case
    if(dp[n]!=0)
    {
        return dp[n];
    }

    int op1,op2,op3;
    op1 = op2 = op3 = INT_MAX;

    if(n%3==0)
    {
        op1 = minstepTD(n/3,dp);
    }
    if(n%2==0)
    {
        op2 = minstepTD(n/2,dp);
    }
    op3 = minstepTD(n-1,dp);

    int ans;
    ans = min(min(op1,op2),op3) + 1;
    return dp[n] = ans;
}

//Bottom Up approach
int minstepBU(int n)
{
    if(n==1)
    {
        return 0;
    }

    int dp[100] = {0};

    for(int i=2;i<=n;i++)
    {
        int op1,op2,op3;
        op1 = op2 = op3 = INT_MAX;

        if(i%3==0)
        {
            op1 = dp[i/3];
        }
        if(i%2==0)
        {
            op2 = dp[i/2];
        }
        op3 = dp[i-1];
        dp[i] = min(min(op1,op2),op3) + 1;
    }


    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    int dp[100] = {0};

    cout<<minstepTD(n,dp)<<endl;
    cout<<minstepBU(n)<<endl;
}