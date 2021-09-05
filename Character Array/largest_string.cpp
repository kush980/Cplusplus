#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char a[1000],largest[1000];
    int l=0,large=0;
    cin.get();
    for(int i=0;i<n;i++)
    {
        cin.getline(a,1000);
        l=strlen(a);
        if(l>large)
        {
            large=l;
            strcpy(largest,a);
        }
    }
    cout<<largest<<" and "<<large<<endl;
    return 0;
}