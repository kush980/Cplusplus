#include<iostream>
#include<bitset>
#include<vector>
using namespace std;

const int n=10000000;
bitset<10000005>b;
vector<int> primes;

void sieve()
{
    b.set();
    b[0]=b[1]=0;
    for(long long int i=2;i<=n;i++)
    {
        if(b[i])
        {
            primes.push_back(i);
            for(long long j=i*i;j<=n;j+=i)
            {
                b[j]=0;
            }
        }
    }
}

bool isprime(long long no)
{
    if(no<=n)
    return b[no]==1?true:false;
    for(long long int i=0;primes[i]*(long long)primes[i]<=no;i++)
    {
        if(no%primes[i]==0)
        return false;
    }
    return true;
}

int main()
{
    sieve();
    long long no;
    cin>>no;
    if(isprime(no))
    cout<<"it is prime";
    else
    {
        cout<<"it is not prime";
    }
}