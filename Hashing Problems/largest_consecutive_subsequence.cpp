#include<iostream>
#include<unordered_map>
using namespace std;

int largest_con_seq(int a[],int n)
{
    unordered_map<int,int> m;

    for(int i=0;i<n;i++)
    {
        int no = a[i];
        if(m.count(no-1)==0 and m.count(no+1)==0)
        {
            m[no]=1;
        }
        else if(m.count(no-1) and m.count(no+1))
        {
            int len1 = m[no-1];
            int len2 = m[no+1];

            int streak = len1 + len2 +1;
            m[no-len1] = streak;
            m[no+len2] = streak;
        }
        else if(!m.count(no-1) and m.count(no+1))
        {
            int len = m[no+1];
            m[no+len] = len+1;
            m[no] = len+1;
        }
        else
        {
            int len = m[no-1];
            m[no-len] = len+1;
            m[no] = len+1;
        }

       
    }
    int largest = 0;
    for(auto p:m)
        {
            largest = max(largest,p.second);
        }
        
    return largest;
}

int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    cout<<largest_con_seq(a,n)<<endl;
}