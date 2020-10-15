#include<iostream>
#include<vector>
using namespace std;


int main()
{
    vector<int> d{10,12,13,11,14};

    //to add another element at the end
    d.push_back(16);

    //to remove element from the back
    d.pop_back();

    //insert one or more elements in the middle
    d.insert(d.begin()+2,4,100);

    //erase one or a range of elements from the middle or anywhere
    d.erase(d.begin()+2,d.begin()+4);

    //to get just the front element of the vector 
    cout<<d.front()<<endl;

    //to get the rearmost element of the vector
    cout<<d.back()<<endl;

    cout<<d.capacity()<<endl;

    //to clear all the elements from the vector
    d.clear();

    for(int x:d)
    {
        cout<<x<<" ";
    }
    cout<<endl;


    //reserve : doubling each time the vector size takes more time so we will reservre some amount of space if elements increases then it will be doubled
    vector<int> v;
    v.reserve(20);
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        int no;
        cin>>no;
        v.push_back(no);
        cout<<v.capacity()<<endl;
    }
    cout<<v.capacity()<<endl;       //in the output it is visible that capacity is not changing

    for(int x:v)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}