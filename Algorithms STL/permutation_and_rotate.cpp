#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int a[]={10,20,30,40,50};
    int n=sizeof(a)/sizeof(int);
    rotate(a,a+2,a+n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

    vector<int> v{10,20,30,40,50};
    rotate(v.begin(),v.begin()+3,v.end());
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    //Next permutation (it prints the next largest sequence or number)
    next_permutation(v.begin(),v.end());
    for(int x:v)  // this statement shows that x belongs to vector v
    {
        cout<<x<<" ";
    }

    cout<<endl;
    //another example of next permutation 
    vector<int> b{1,2,3};
    for(int i=0;i<v.size();i++)
    {
        cout<<b[i]<<" ";
    }
    cout<<endl;

    next_permutation(b.begin(),b.end());
    next_permutation(b.begin(),b.end());      //if we permutate twice then the sequnce or no. 2 times greater will be showm
    for(int y:b)
    {
        cout<<y<<" ";
    }
}