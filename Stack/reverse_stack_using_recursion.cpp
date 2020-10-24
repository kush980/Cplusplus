#include<iostream>
#include<stack>
using namespace std;

void insertatbottom(stack<int> &s,int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }
    //rec case;
    int data=s.top();
    s.pop();
    insertatbottom(s,x);
    s.push(data);
}


void reversestack(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }

    //otherwise
    int x=s.top();
    s.pop();
    //recursively reverse the stack
    reversestack(s);
    insertatbottom(s,x);

}

int main()
{
    stack<int> s;
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s.push(x);
    }

    reversestack(s);
    while(!s.empty())
    {
        cout<<s.top()<<",";
        s.pop();
    }
    cout<<endl;

    return 0;
}