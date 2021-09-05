#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class graph
{

    vector<pair<int,int>> *l;
    int V;
public:
    graph(int n)
    {
        V=n;
        l=new vector<pair<int,int>>[n];
    }

    void addEdge(int x,int y,int w)
    {
        l[x].push_back({y,w});
        l[y].push_back({x,w});
    }

    int prim_MST()
    {
        //1. declare min heap
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > Q;

        //init visited array
        bool *vis = new bool[V]{0};
        int ans=0;

        Q.push({0,0});
        while(!Q.empty())
        {
            auto min1 = Q.top();
            Q.pop();

            int t = min1.second;
            int wt = min1.first;

            if(vis[t])
            {
                continue;
            }

            ans+=wt;
            vis[t]=1;

            //add the new edge to the queue
            for(auto x:l[t])
            {
                if(vis[x.first]==0)
                {
                    Q.push({x.second,x.first});
                }
            }
        }
        return ans;
    }

};

int main()
{
    int n,m;
    cin>>n>>m;
    graph g(n);
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        g.addEdge(x-1,y-1,w);
    }
    cout<<g.prim_MST()<<endl;
}