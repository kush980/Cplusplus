#include<iostream>
using namespace std;

int wines(int wine[],int i,int j,int y,int dp[][100])
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
    int op1 = wine[i]*y + wines(wine,i+1,j,y+1,dp);
    int op2 = wine[j]*y + wines(wine,i,j-1,y+1,dp);

    return dp[i][j] = max(op1,op2);
}

int main()
{
    int n;
    cin>>n;
    int wine[n];
    for(int i=0;i<n;i++)
    {
        cin>>wine[i];
    }
    int dp[100][100] = {0};
    cout<<wines(wine,0,n-1,1,dp)<<endl;
}