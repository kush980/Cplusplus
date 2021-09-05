#include<iostream>
using namespace std;
float binary_square(int n,int p)
{
    int s=0;
    int e=n;

    float ans=-1;
    while(s<=e)
    {
        int mid=(s+e)>>1;
        if(mid*mid==n)
        {
            return mid;
        }
        else if(mid*mid<n)
        {
            ans=mid;
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    float inc=0.1;
    for(int i=1;i<=p;i++)
    {
        while(ans*ans<=n)
        {
            ans+=inc;
        }
        ans=ans-inc;
        inc=inc/10;
    }
    return ans;
}


int main()
{
    int n;
    cin>>n;

    cout<<binary_square(n,4)<<endl;
}