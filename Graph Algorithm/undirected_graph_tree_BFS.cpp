#include<iostream>
#include<list>
#include<queue>
using namespace std;

class graph
{

    list<int> *l;
    int V;

public:
    graph(int V)
    {
        this->V=V;
        l = new list<int>[V];
    }

    void addEdge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool is_tree()
    {
        bool *visited = new bool[V];
        int *parent = new int[V];

        queue<int> q;
        for(int i=0;i<V;i++)
        {
            visited[i]=false;
            parent[i]=i;
        }

        int src=0;
        q.push(src);
        visited[src]=true;

        while(!q.empty())
        {
            int node  = q.front();
            q.pop();

            for(auto nbr:l[node])
            {
                if(visited[nbr]==true and parent[node]!=nbr)
                {
                    return false;
                }

                else if(!visited[nbr])
                {
                    visited[nbr]=true;
                    parent[nbr]=node;
                    q.push(nbr);
                }
            }
        }
        return true;
    }

};

int main()
{
    graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    //g.addEdge(0,3);

    if(g.is_tree())
    cout<<"its a tree"<<endl;
    else
    {
        cout<<"its not a tree"<<endl;
    }
    
}