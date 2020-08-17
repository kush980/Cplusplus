#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,i=0,j=0,s,cs=0;
    cin>>n;
    int a[n];
    for(int k=0;k<n;k++)
    {
        cin>>a[k];
    }
    sort(a,a+n);
    j=n-1;
    cin>>s;
    while(i<j)
    {
        cs=a[i]+a[j];
        if(cs>s)
        {
           j--; 
        }
        else if(cs<s)
        {
            i++;
        }
        else if(cs==s)
        {
            cout<<a[i]<<" and "<<a[j]<<endl;
            i++;
            j--;
        }
    }
    return 0;
}