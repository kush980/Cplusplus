#include<iostream>
#include<list>
using namespace std;


class Queue
{
    int cs;
    list<int> l;
    public:
    
    Queue()
    {
        cs=0;
    }

    bool empty()
    {
        return cs==0;
    }
    void push(int data)
    {
        l.push_back(data);
        cs++;
    }

    void pop()
    {
        if(!empty())
        {
            cs--;
            l.pop_front();
        }
    }

    int front()
    {
        return l.front();
    }
};

int main()
{
    Queue q;
    for(int i=1;i<11;i++)
    {
        q.push(i);
    }

    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}