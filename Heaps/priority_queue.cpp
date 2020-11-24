#include<iostream>
#include<queue>
using namespace std;

int main()
{
    //priority_queue<int> pq;         //automatically set to maxheap
    priority_queue<int,vector<int>,greater<int>> pq;    //greater is a inbuilt comparater
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int no;
        cin>>no;
        pq.push(no);
    }

    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}