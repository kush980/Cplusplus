#include<iostream>
#include<set>
using namespace std;

class compare
{
    public:
    bool operator()(pair<string,int> p1,pair<string,int>p2)
    {
        return p1.second<p2.second;
    }  
};

int main()
{
    pair<string,int> p1=make_pair("A",40);
    pair<string,int> p2=make_pair("B",100);
    pair<string,int> p3=make_pair("C",120);
    pair<string,int> p4=make_pair("D",10);

    //using multiset to store pair and print them accod=rding lexographic and compare class
  //  multiset<pair<string,int>,compare> m;   //for numeric and with class function
    multiset<pair<string,int> >m1  ;      //for lexographic and without class
    m1.insert(p1);
    m1.insert(p2);
    m1.insert(p3);
    m1.insert(p4);

    for(auto x:m1)
    {
        cout<<x.first<<"-"<<x.second<<endl;
    }
    cout<<endl;
}