#include<iostream>
using namespace std;
int sumofallsubmatrix(int **ar,int m,int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int tl=(i+1)*(j+1);
            int br=(n-i)*(n-j);
            sum+=(tl*br)*ar[i][j];
        }
    }
    return sum;
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
    cout<<sumofallsubmatrix(arr,n,m)<<endl;
}