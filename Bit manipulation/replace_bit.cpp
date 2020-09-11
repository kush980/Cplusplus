#include<iostream>
using namespace std;

int clearrangebits(int n,int i,int j)
{
    int ones = (~0);
    int a = ones << (j+1);
    int b = (1<<i)-1;
    int mask = a|b;
    return n&mask;
}

int replacebit(int n,int m,int i,int j)
{
    int n_=clearrangebits(n,i,j);
    int ans = n_|(m<<i);
    return ans;
}
int main()
{
    int n,i,j;
    cin>>n>>i>>j;
    int m;
    cin>>m;
    cout<<replacebit(n,m,i,j)<<endl;
}