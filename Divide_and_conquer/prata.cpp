#include<iostream>
#include<climits>
using namespace std;

bool isvalid(int p,int rank[],int cooks,int curr_min)
{
    int cnt=0;
    for(int i=0;i<cooks;i++)
    {
        int j=1;
        int sum=0;
        while(sum<=curr_min)
        {
            sum+=j*rank[i];
            j++;
            cnt++;
        }
        cnt--;
    }
        if(cnt>=p)
        return true;
        else
        return false;
}


int findmin(int p,int rank[],int cooks)
{
    int s=0;
    int e=INT_MAX;
    int ans=-1;
    while(s<=e)
    {
        int mid=(s+e)>>1;
        if(isvalid(p,rank,cooks,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int p,cooks;
        cin>>p>>cooks;
        int rank[cooks];
        for(int i=0;i<cooks;i++)
        {
            cin>>rank[i];
        }
        cout<<findmin(p,rank,cooks)<<endl;
    }
    return 0;
}