#include<iostream>
#include<set>
#include<climits>
#include<algorithm>
using namespace std;


int main()
{
    set<pair<int,int> > s;

    s.insert(make_pair(10,1));
    s.insert(make_pair(10,5));

    s.insert(make_pair(10,4));
    s.insert(make_pair(20,1));
    s.insert(make_pair(20,100));
    s.insert(make_pair(5,4));

    s.insert(make_pair(4,1));

    s.erase(s.find(make_pair(5,4)));
    s.insert(make_pair(5,3));

    auto it = s.upper_bound(make_pair(10,INT_MAX));
    cout<<it->first<<" ,"<<it->second;
    cout<<endl;
    for(auto x:s)
    {
        cout<<x.first<<","<<x.second<<endl;
    }



}