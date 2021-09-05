#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,pair<int,int> > node;

vector<int> mergeKsortedarray(vector<vector<int>>arr)
{
    vector<int> result;

    priority_queue<node,vector<node>,greater<node>>pq;      //minheap

    for(int i=0;i<arr.size();i++)
    {
        pq.push({arr[i][0],{i,0}});
    }

    //remove the element one by one and insert in the result vector 
    while(!pq.empty())
    {
        node current = pq.top();
        pq.pop();
        int element = current.first;        //to store the value of element
        int x = current.second.first;       //the store the which array
        int y = current.second.second;      //to store the index of element

        result.push_back(element);

        if(y+1<arr[x].size())
        {
            pq.push({arr[x][y+1],{x,y+1}});
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> a{{2,6,12,15},
                        {1,3,14,20},
                        {3,5,8,10}};
    vector<int> output = mergeKsortedarray(a);

    for(auto i:output)
    {
        cout<<i<<" ";
    }
}