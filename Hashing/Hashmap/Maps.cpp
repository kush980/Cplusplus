#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    map<string,int> m;

    //1. insert
    m.insert(make_pair("Apple",300));

    pair<string,int> p;
    p.first = "Mango";
    p.second = 200;

    m.insert(p);

    m["Guava"] = 125;
    string fruit;
    cin>>fruit;

    auto it = m.find(fruit);
    if(it!=m.end())
    {
        cout<<"The price of "<<fruit<<" is: "<<m[fruit]<<endl;
    }
    else
    {
        cout<<fruit<<" is not present in the map"<<endl;
    }

    //erase
    m.erase(fruit);

    //using count function for the search 
    //map only stores unique keys once
    if(m.count(fruit))
    {
        cout<<"The price of fruit is "<<m[fruit]<<endl;
    }
    else
    {
        cout<<fruit<<" is not present"<<endl;
    }

    m["Kiwi"] = 500;
    m["Litchi"] = 120;

    for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<it->first<<" and "<<it->second<<endl;
    }

    for(auto x:m)
    {
        cout<<x.first<<" : "<<x.second<<endl;
    }
    
}