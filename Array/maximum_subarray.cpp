#include<iostream>
using namespace std;
int main()
{
    int n,csum=0,msum=0,l=0,r=0,i,j;
    cin>>n;
    int a[1000];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            csum=0;
            for(int k=i;k<=j;k++)
                csum+=a[k];
        if(csum>msum)
        {
            msum=csum;
            l=i;
            r=j;
        }
    }
    }
     cout<<msum<<endl;
    for(i=l;i<=r;i++)
    {
        cout<<a[i]<<",";
    }
    return 0;
}