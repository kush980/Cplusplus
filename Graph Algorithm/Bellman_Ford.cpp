#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> bellman_ford(int n,int src,vector<vector<int>> edges)
{
    vector<int> dist(n+1,INT_MAX);
    dist[src]=0;

    for(int i=0;i<n-1;i++)
    {
        for(auto edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if(dist[u]!=INT_MAX and dist[u]+wt<dist[v])
            {
                dist[v]=dist[u]+wt;
            }
        }
    }
    //negative cycle check
    for(auto edge:edges)
    {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        if(dist[u]!=INT_MAX and dist[u]+wt<dist[v])
        {
            cout<<"negative cycle found"<<endl;
            exit(0);
        }
    }
    return dist;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++)
    {
        int x,y,wt;
        cin>>x>>y>>wt;
        edges.push_back({x,y,wt});
    }

    //bellman algorithm
    vector<int> distances = bellman_ford(n,1,edges);

    for(int i=1;i<=n;i++)
    {
        cout<<"Node "<<i<<" is at a distance of "<<distances[i]<<endl;
    }
}

