#include<iostream>
using namespace std;

//generic programming allows us to use one function in any datatype

///linear search
template<typename T> 
int search(T a[],int n,T k)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==k)
        return i;
    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int k;
    cin>>k;
    cout<<"integar type search "<<search(a,n,k)<<endl;      //this is integar type search

    float af[n];
    for(int i=0;i<n;i++)
    cin>>af[i];
    float key;
    cin>>key;
    cout<<"float type search "<<search(af,n,key)<<endl;     //float type search from the same int program used as template datatype and can be used for any other searches like char or strings or others.


}