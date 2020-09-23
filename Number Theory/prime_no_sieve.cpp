#include<iostream>
using namespace std;

void primesieve(int *p,int n)         // takes time complexity of O(N log log N)
{
    for(int i=3;i<=n;i+=2)
    {
        p[i]=1;
    }
    for(int i=3;i<=n;i+=2)
    {
        if(p[i]==1)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                p[j]=0;
            }
        }
    }
    //special case
    p[2]=1;
    p[1]=p[0]=0;
}

int main()
{
    int n;
    cin>>n;
    int p[n]={0};
    primesieve(p,n);
    for(int i=0;i<=n;i++)
    {
        if(p[i]==1)
        {
            cout<<i<<" ";
        }
    }
}