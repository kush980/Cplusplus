#include <iostream>
#include<vector>
using namespace std;

void print(vector<int> v)
{
    for(auto x:v)
    {
        cout<<x<<" ";
    }
    cout<<endl;
}

//O(NLogN)
void buildHeap(vector<int> &v)
{
    for(int i=2;i<v.size();i++)
    {
        int idx=i;
        int parent = i/2;
        while(idx>1 && v[idx]>v[parent])
        {
            swap(v[idx],v[parent]);
            idx = parent;
            parent = parent / 2;
        }
    }
}

bool minHeap = false;
bool compare(int a,int b)
{
    if(minHeap)
    {
        return a < b;
    }
   else
   {
        return a > b;
   }
}

void heapify(vector<int> &v,int idx)
    {
        int left = 2*idx;
        int right = left + 1;

        int min_idx = idx;
        int last = v.size() - 1;

        if(left<=last && compare(v[left],v[idx]))
        {
            min_idx = left;
        }
        if(right<=last && compare(v[right],v[min_idx]))
        {
            min_idx = right;
        }

        if(min_idx!=idx)
        {
            swap(v[idx],v[min_idx]);
            heapify(v,min_idx);
        }
    }

//buildHeap Optimised approach O(N)
void buildHeapOptimised(vector<int> &v)
{
    for(int i=v.size()-1/2;i>=1;i--)
    {
        heapify(v,i);
    }
}

int main() {

    vector<int> v{-1,10,20,5,6,1,8,9,4};
    print(v);
    buildHeap(v);
    print(v);
    buildHeapOptimised(v);
    print(v);
    return 0;

}

