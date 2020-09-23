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


int no_of_divisors(int m, vector<int>&prime)
{
    int i=0;
    int p=prime[0];
    int ans=1;
    while(p*p<=m)
    {
        if(m%p==0)
        {
            int cnt=0;
            while(m%p==0)
            {
                cnt++;
                m=m/p;
            }
            ans=ans*(cnt+1);
        }
        i++;
        p=prime[i];
    }
    if(m!=1)
    {
        ans=ans*2;
    }
    return ans;
}

int main()
{
    int n=1000000;
    int p[n]={0};
    vector<int> primes=primesieve(p,10000);
    int t;
    cin>>t;
    while(t--)
    {
        int no;
        cin>>no;

        int divs=no_of_divisors(no,primes);
        cout<<divs<<endl;
    }

}