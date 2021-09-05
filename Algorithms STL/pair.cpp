#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    pair<int ,char> p;
    p.first=10;
    p.second='y';
    cout<<p.first<<" "<<p.second<<endl;

    pair<int,char> p2(p);    //copied the elements of first to the sencond one
    cout<<p2.first<<endl;
    cout<<p2.second<<endl;

    pair<int,string> p3=make_pair(100,"BMW");
    cout<<p3.first<<endl;
    cout<<p3.second<<endl;

    int a,b;
    cin>>a>>b;
    pair<int,int> p4=make_pair(a,b);
    cout<<p4.first<<endl<<p4.second<<endl;

    //pair of arrays , vectors anything van be created 

    pair<pair<int,int>,string> bike;
    bike.second="Harley";
    bike.first.first=100;
    bike.first.second=110;

    cout<<bike.first.second<<endl;
    cout<<bike.second<<endl;
}