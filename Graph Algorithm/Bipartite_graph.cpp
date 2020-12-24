#include<iostream>
#include<vector>
using namespace std;

bool dfs_helper(vector<int> graph[] , int node, int *visited , int parent , int color)
{
    visited[node] = color;

    for(auto nbr:graph[node])
    {
        if(visited[nbr]==0)
        {
            int subprob = dfs_helper(graph,nbr,visited,node,3-color);

            if(subprob==false)
            {
                return false;
            }
            else if(nbr!=parent and color==visited[nbr])
            {
                return false;
            }
            
        }
    }
    return true;
}


bool dfs(vector<int> graph[],int n)
{
    int visited[n]={0};
    int color=1;

    int ans = dfs_helper(graph,0,visited,-1,color);
    for(int i=0;i<n;i++)
    {
        cout<<i<<" -color "<<visited[i]<<endl;
    }

    return ans;
}

int main()
{
   int n,m;
    cin>>n>>m;
    vector<int> graph[n];

    while(m--)
    {
        int x,y;
        cin>>x>>y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    if(dfs(graph,n))
    {
        cout<<"Its bipartite";
    }
    else
    {
        cout<<"not bipartite";
    }
    
}