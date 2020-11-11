#include<iostream>
#include<set>
using namespace std;

typedef multiset<int>::iterator It;

int main()
{
    int a[]={10,10,10,20,20,30,80,30,56};
    multiset<int> m(a,a+9);


    m.erase(20);
    m.insert(40);
    for(auto x:m)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    //find
    auto it1 = m.find(10);
    cout<<*it1<<" ";
    cout<<endl;
    //count
    cout<<m.count(10)<<endl;

    //for all elements which are equal to 10
    pair<It,It> p=m.equal_range(10);

    for(auto it=p.first;it!=p.second;it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    //lower and upper bound
    for(auto it=m.lower_bound(10);it!=m.upper_bound(76);it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}