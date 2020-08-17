#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    int csum=0,msum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        csum+=a[i];
        if(csum<0)
        {
            csum=0;
        }
        msum=max(csum,msum);
    }
    cout<<"maximum sum is "<<msum<<endl;
    return 0;
}