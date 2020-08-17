#include<iostream>
using namespace std;
int maxsumsubmatrix(int **arr,int n,int m)
{
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-2;j>=0;j--)
        {
            arr[i][j]+=arr[i][j+1];
        }
    }
    for(int i=m-1;i>=0;i--)
    {
        for(int j=n-2;j>=0;j--)
        {
            arr[j][i]+=arr[j+1][i];
        }
    }
    int result= INT16_MIN;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            result=max(result,arr[i][j]);
        }
    }
    return result;

}
int main()
{

  int m,n;
    cin>>n>>m;
    int **arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[m];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<maxsumsubmatrix(arr,n,m)<<endl;
}