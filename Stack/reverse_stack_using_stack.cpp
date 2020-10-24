#include<iostream>
#include<stack>
using namespace std;

void transfer(stack<int> &s1,stack<int> &s2,int n)
{
    s2.push(s1.top());
    s1.pop();
}

void reversestack(stack<int> &s1)
{
    stack<int> s2;
    
    int n=s1.size();

    for(int i=0;i<n;i++)
    {
        int x=s1.top();
        s1.pop();

        //transfer the n-i-1 element to s2
        transfer(s1,s2,n-i-1);

        //now put the element x in s1;
        s1.push(x);

        //now again transfer the elements of s2 in s1
        transfer(s2,s1,n-i-1);

    }
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