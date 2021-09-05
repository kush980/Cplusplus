#include<iostream>
#include<stack>
using namespace std;

bool isvalid(char *a)
{
    stack<char> s;

    for(int i=0;a[i]!='\0';i++)
    {
        char ch=a[i];
        if(ch=='(')
        {
            s.push(ch);
        }

        else if(ch==')')
        {
            if(s.empty() or s.top()!='(')
            {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}


int main()
{
    char a[100];
    cin>>a;

    if(isvalid(a))
    {
        cout<<"yes";
    }
    else
    {
        cout<<"no";
    }
    
}