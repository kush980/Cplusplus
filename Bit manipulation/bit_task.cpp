#include<iostream>
using namespace std;

bool isodd(int n)
{
    return (n&1);
}
int getbit(int n,int i)
{
    int mask = 1<<i;
    int bit = (n&mask)> 0 ? 1 : 0;
    return bit;
}
int setbit(int n,int i)
{
    int mask = 1<<i;
    int ans = n|mask;
    return ans;
}
int clearbit(int &n,int i)
{
    int mask =~(1<<i);
    n=n&mask;
}
int updatebit(int &n,int i,int v)
{
    int mask=~(1<<i);
    int clear_n=n&mask;
    n=clear_n|(v<<i);
}

int clearlastbits(int n,int i)
{
    int mask = (-1<<i);
    return n&mask;
}

int clearrangebits(int n,int i,int j)
{
    int ones = (~0);
    int a = ones << (j+1);
    int b = (1<<i)-1;
    int mask = a|b;
    return n&mask;
}
int main()
{
    int n,i,j;
    cin>>n;
    cin>>i;
    cin>>j;
    //cout<<isodd(n)<<endl;
    cout<<getbit(n,i)<<endl;
    cout<<setbit(n,i)<<endl;
    cout<<clearlastbits(n,i)<<endl;
    cout<<clearrangebits(n,i,j)<<endl;
    // clearbit(n,i);
    // cout<<n<<endl;
    updatebit(n,2,0);
    updatebit(n,3,1);
    cout<<n<<endl;
}