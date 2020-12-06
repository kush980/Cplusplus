#include<iostream>
#include<unordered_set>
using namespace std;

int findLargestSeq(int a[],int n)
{
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    {
        s.insert(a[i]);
    }
    int max_streak=0;
    for(int i=0;i<n;i++)
    {
        if(s.find(a[i]-1)==s.end())
        {
            //now this is the starting od the streak
            //iterate till it consecutive breaks
            int next = a[i]+1;
            int streak_len=1;
            while(s.find(next)!=s.end())
            {
                next+=1;
                streak_len+=1;
            }
            max_streak = max(streak_len,max_streak);
        }
    }
    return max_streak;
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

    cout<<findLargestSeq(a,n)<<endl;
}