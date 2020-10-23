#include<iostream>
#include<list>
using namespace std;

int main()
{
    //declaration 
    list<int> l;

    //init with value
    list<int> l1{1,2,3,4,5};

    //different datatypes
    list<string> l2{"apple","watermelon","pineapple","guava"};


    //sorting
    l1.sort();
    l2.sort();

    //reverse the list
    l1.reverse();

    //last element of the list
    cout<<l1.back()<<endl;
    l1.pop_back();
    l1.push_back(10);

    //front element of the list
    cout<<l1.front()<<endl;
    l1.pop_front();
    l1.push_front(50);

    //iterating over the list

    for(auto it=l1.begin();it!=l1.end();it++)
    {
        cout<<(*it)<<"->";
    }
    cout<<endl;

    for(auto s:l2)
    {
        cout<<s<<"-->";
    }
    cout<<endl;
}