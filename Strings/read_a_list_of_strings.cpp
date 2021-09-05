#include<iostream>
using namespace std;
int main()
{
   
    int n;
    cin>>n;
   // cin.get();
     char a[100][100];
     for(int i=0;i<n;i++)
    {
        cin.getline(a[i],1000);
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}