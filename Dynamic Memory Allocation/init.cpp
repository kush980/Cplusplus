#include<iostream>
using namespace std;
int main()
{
    //static allocation + deallocation is done by compiler
    int b[100];
    cout<<sizeof(b)<<endl;
    cout<<b<<endl; //symbol table
    // here b cant be overwritten , bcoz b is a part of read onlly memory

    //Dynamic allocation
    int n;
    cin>>n;
    int *a=new int[n];
    cout<<sizeof(a)<<endl;
    cout<<a<<endl;          //variable a that is created inside the static memory -> overwritten

    //No change
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cout<<a[i]<<" ";
    }

    //freeup the space
    delete[] a;

    return 0;

}