#include<iostream>
#include<algorithm>
using namespace std;
bool compare(int a ,int b)       //to return in decreasing order
{
    return a>b;
}
int main()
{
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,compare);     //decreasing order
  //  sort(a,a+n);             //increasing order
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" "; 
    }
    return 0;
}