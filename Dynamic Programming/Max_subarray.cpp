#include<iostream>
using namespace std;

int maxSum(int a[],int n)
{
    int dp[100] = {0};

    dp[0] = a[0]>0?a[0]:0;
    int max1 = dp[0];

    for(int i=1;i<n;i++)
    {
        dp[i] = dp[i-1]+a[i];
        if(dp[i]<0)
        {
            dp[i] = 0;
        }
        max1 = max(max1,dp[i]);
    }

    return max1;
}

//space optimised algo
//kadane's algo
//exception - when all elements are -ve

int maxSumSpace(int a[],int n)
{
    int csum = 0;
    int msum = 0;

    for(int i=0;i<n;i++)
    {
        csum+=a[i];
        if(csum<0)
        csum = 0;
        msum = max(msum,csum);

    }
    return msum;
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

    cout<<maxSum(a,n)<<endl;
    cout<<maxSumSpace(a,n)<<endl;

}