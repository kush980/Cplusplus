#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> a;      //declaration of vector
    vector<int> b(5,10);        //this vector contains 5 integers of number 10
    vector<int> c(b.begin(),b.end());      //copies all the elements of vector b;
    vector<int> d{10,12,13,11,14};

    //printing method
    for(int i=0;i<c.size();i++)
    {
        cout<<c[i]<<" ";
    }
    cout<<endl;

    for(auto it=b.begin();it!=b.end();it++)
    {
        cout<<(*it)<<" ";
    }
    cout<<endl;

    for(int x:d)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    //initializing a vector that will take input from the user
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int no;
        cin>>no;
        v.push_back(no);
    }
    for(auto x:v)
    {
        cout<<x<<" ";
    }
    cout<<endl;


    //compairing the vector d and v on the memory level as both has 5 elements 
    cout<<v.size()<<endl;
    cout<<v.capacity()<<endl;       //size of underlying array
    cout<<v.max_size()<<endl;       //maximum number of elements this vector can hold in the worst case acc to the avbl memory in the system

    //now vector d
    cout<<d.size()<<endl;
    cout<<d.capacity()<<endl;       //size of the underlying array
    cout<<d.max_size()<<endl;       //max no of elements this vector can hold can hold in the worst case acc to the avbl memory in the system
}