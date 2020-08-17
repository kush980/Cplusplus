#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],cus[n];
    int csum=0,msum=0,l=0,r=0,i,j;
    cin>>a[0];
    cus[0]=a[0];
    for(i=1;i<n;i++)
    {
        cin>>a[i];
        cus[i]=cus[i-1]+a[i];
    }
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            csum=0;
            csum=cus[j]-cus[i-1];
           // cout<<csum;
            if(csum>msum)
            {
                msum=csum;
                l=i;
                r=j;
            }
        }
    }
    cout<<"maximum sum is "<<msum<<endl;
    for(i=l;i<=r;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}