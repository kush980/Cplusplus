#include<iostream>
#include<stack>
using namespace std;

void stackspan(int prices[],int n,int span[])
{
    stack<int> s;
    s.push(0);

    span[0]=1;

    //loop for the rest of the days
    for(int i=1;i<n;i++)
    {
        int current=prices[i];
        //pop the elements which are lesser than the current element
        while(!s.empty() && prices[s.top()]<=current)
        {
            s.pop();
        }

        if(!s.empty())
        {
            int prev = s.top();
            span[i]=i-prev;
        }

        else
        {
            span[i]=i+1;
        }
        
        //push this element into the stack
        s.push(i);
    }
}


int main()
{
    int n;
    cin>>n;
    int prices[n];
    for(int i=0;i<n;i++)
    {
        cin>>prices[i];
    }

    int span[100000]={0};

    stackspan(prices,n,span);
    for(int i=0;i<n;i++)
    {
        cout<<span[i]<<",";
    }
    cout<<endl;
    return 0;
}