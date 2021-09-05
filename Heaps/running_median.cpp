#include<iostream>
#include<queue>
using namespace std;

int main()
{

    priority_queue<int> leftheap;       //maxheap
    priority_queue<int,vector<int>,greater<int>>rightheap;      //minheap

    int d;      //data
    cin>>d;
    float med = d;
    leftheap.push(d);

    cout<<"Median "<<med<<endl;
    cin>>d;

    while(d!=-1)
    {
        if(leftheap.size()>rightheap.size())
        {
            if(d<med)
            {
                rightheap.push(leftheap.top());
                leftheap.pop();
                leftheap.push(d);
            }
            else
            {
                rightheap.push(d);
            }
            med = (leftheap.top() + rightheap.top())/2.0;
        }
        else if(leftheap.size()==rightheap.size())
        {
            if(d<med)
            {
                leftheap.push(d);
                med = leftheap.top();
            }
            else
            {
                rightheap.push(d);
                med = rightheap.top();
            }
        }
        else
        {
            if(d>med)
            {
                leftheap.push(rightheap.top());
                rightheap.pop();
                rightheap.push(d);
            }
            else
            {
                leftheap.push(d);
            }

            med = (leftheap.top()+rightheap.top())/2.0;
        }
        cout<<"Median "<<med<<endl;
        cin>>d;
    }
    
    return 0;
}