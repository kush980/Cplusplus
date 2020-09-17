#include<iostream>
#include<vector>
using namespace std;

vector<int> primesieve(int *p,int n)         
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
    
    vector<int>prime;
    prime.push_back(2);
    
    for(int i=3;i<=n;i+=2)
    {
        if(p[i]==1)
        prime.push_back(i);
    }
    return prime;
}

vector<int> factorize(int m,vector<int> &prime)
{
    vector<int>factors;
    factors.clear();

    int i=0;
    int p=prime[0];
    int temp=m;
    while(p*p<=m)
    {
        if(m%p==0)
        {
            factors.push_back(p);
            while(m%p==0)
            {
                m=m/p;
            }
        }
        i++;
        p=prime[i];
    }
    if(m!=1)
    {
        factors.push_back(m);
    }
    return factors;
}

int main()
{
    int M=1000000;
    int p[M]={0};
    vector<int>prime=primesieve(p,100);

    int t;
    cin>>t;
    while(t--)
    {
        int no;
        cin>>no;
        vector<int>factors=factorize(no,prime);

        for(auto f:factors)
        {
            cout<<f<<" ";
        }
        cout<<endl;
    }
    return 0;
}