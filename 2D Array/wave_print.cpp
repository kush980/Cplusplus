#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n][m],b=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            a[i][j]=b;
            b=b+1;
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    for(int j=0;j<m;j++)
    {
        if(j%2==0)
        {
            for(int i=0;i<n;i++)
            {
            cout<<a[i][j]<<" ";
             }
        }
        else
        {
            for(int i=n-1;i>=0;i--)
            {
                cout<<a[i][j]<<" ";
            }
        }
        
    }
    return 0;
}