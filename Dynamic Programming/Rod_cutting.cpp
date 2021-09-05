#include<iostream>
#include<climits>
using namespace std;

int Max_Profit(int prices[],int n,int dp[])
{
    //base case
    if(n<=0)
    {
        return 0;
    }

    //lookup
    if(dp[n]!=0)
    {
        return dp[n];
    }

    //rec case
    int ans = INT_MIN;
    for(int i=0;i<n;i++)
    {
        int cut = i+1;
        int current_ans = prices[i] + Max_Profit(prices,n-cut,dp);
        ans = max(current_ans,ans);
    }
    return dp[n] = ans;
}

int Max_profitBU(int n,int *prices)
{
    int dp[n+1];
    dp[0] = 0;

    for(int len=1;len<=n;len++)
    {
        int ans = INT_MIN;
        for(int i=0;i<len;i++)
        {
            int cut = i+1;
            int current_ans = prices[i] + Max_profitBU(n-cut,prices);
            ans = max(current_ans,ans);
        }
        dp[len] = ans;
    }
    return dp[n];
}


int main()
{
    int n;
    cin>>n;
    int price[n];
    for(int i=0;i<n;i++)
    {
        cin>>price[i];
    }
    int dp[100] = {0};
    cout<<Max_Profit(price,n,dp)<<endl;
    cout<<Max_profitBU(n,price)<<endl;
}