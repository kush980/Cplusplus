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
    l1.push_front(10);

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


    //some more functions 

    int n;
    // cin>>n;
    // l1.remove(n);
    for(auto s:l1)
    {
        cout<<s<<"-->";
    }
    cout<<endl;

    //erase element by position
    auto it=l1.begin();
    it++;
    it++;
    l1.erase(it);
    for(auto s:l1)
    {
        cout<<s<<"-->";
    }
    cout<<endl;

    //insert element by position 
    auto it1=l2.begin();
    it1++;
    it1++;
    l2.insert(it1,"banana");
    for(auto s:l2)
    {
        cout<<s<<"-->";
    }
    cout<<endl;

    cout<<"Rohit chutiya hai aur uska guitar bhi"<<endl;

}