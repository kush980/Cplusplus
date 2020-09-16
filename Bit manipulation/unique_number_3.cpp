#include<iostream>
using namespace std;
int main()
{
    int a[64]={0};
    int n;
    cin>>n;
    int no;
    for(int i=0;i<n;i++)
    {
        cin>>no;
        int j=0;
        while(no>0)
        {
            a[j]+=(no&1);
            j++;
            no=no>>1;
        }
    }
    int p=1;
    int ans=0;
    for(int i=0;i<64;i++)
    {
        a[i]=a[i]%3;
        ans+=(a[i]*p);
        p=p*2;
    }
    cout<<ans<<endl;
}