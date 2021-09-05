#include<iostream>
using namespace std;
int main()
{
    int i,n;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(int j=1;j<=n-i;j++)
        {
            cout<<" ";
        }
        int o=i;
        for(int in=1;in<=i;in++)
        {
            cout<<o;
            o+=1;
        }
        o=o-2;
        for(int dc=1;dc<=i-1;dc++)
        {
            cout<<o;
            o=o-1;
        }
         cout<<endl;
    }
   
    return 0;
}
