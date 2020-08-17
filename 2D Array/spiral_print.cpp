#include<iostream>
using namespace std;
void spiralprint(int a[][1000],int m,int n)
{
    int startrow=0;
    int startcol=0;
    int endcol=m-1;
    int endrow=n-1;
    while(startrow<=endrow && startcol<=endcol)
    {
        for(int i=startcol;i<=endcol;i++)
        {
        cout<<a[startrow][i]<<" ";
        }
    startrow++;
    for(int j=startrow;j<=endrow;j++)
    {
        cout<<a[j][endcol]<<" ";
    }
    endcol--;
    if(startcol<endcol)
    {
    for(int i=endcol;i>=startcol;i--)
    {
        cout<<a[endrow][i]<<" ";
    }
    endrow--;
    }
    if(startrow<endrow)
    {
        for(int j=endrow;j>=startrow;j--)
        {
            cout<<a[j][startcol]<<" ";
        }
    
    startcol++;
    }

}
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a[1000][1000],b=1;
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
    spiralprint(a,m,n);   
    return 0;
}