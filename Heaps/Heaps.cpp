#include <iostream>
#include<vector>
using namespace std;

class Heap 
{
    vector<int> v;
    bool minHeap;

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

    void heapify(int idx)
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
            heapify(min_idx);
        }
    }

    public:

        Heap(int default_size = 10 , bool type = true)
        {
            v.reserve(default_size);
            v.push_back(-1);
            minHeap = type;
        }

        void push(int d)
        {
            v.push_back(d);
            int idx = v.size() - 1;
            int parent = idx/2;

            //keep pushing to the top till you reach a root node or stop midway beacuse current element is already greater than parent node
            while(idx > 1 && compare(v[idx],v[parent]))
            {
                swap(v[idx],v[parent]);
                idx = parent;
                parent = parent / 2;
            }
        }

        int top()
        {
            return v[1];
        }

        void pop()
        {
            //1st step - swap the first element to last element
            int last_idx = v.size() - 1;
            swap(v[1],v[last_idx]);

            //2nd step - delete the last element which is the root node after swapping
            v.pop_back();

            //3rd step - Heapify
            heapify(1);

        }

        bool empty()
        {
            return v.size()==1;
        }
};


int main() {
    
    //Heap h; //for min heap and the size is deafult set to 10

    Heap h(10,false);   //false for max heap


    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int no;
        cin>>no;
        h.push(no);
    }

    while(!h.empty())
    {
        cout<<h.top()<<" ";
        h.pop();
    }

    return 0;
}
