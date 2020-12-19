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

    bool cycle_helper(int node,bool *visited,int parent)
    {
        visited[node]=true;
        //recursively visit the nbr
        for(auto nbr:l[node])
        {
            if(!visited[nbr])
            {
                bool is_cycle = cycle_helper(nbr,visited,node);
                if(is_cycle)
                {
                    return true;
                }
            }
            else if(nbr!=parent)
            {
                return true;
            }
        }
        return false;

    }

    bool cycle()
    {
        bool *visited = new bool[V];

        for(int i=0;i<V;i++)
        {
            visited[i]=false;
        }

        return cycle_helper(0,visited,0);
    }

};

int main()
{
    graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    //g.addEdge(4,0);

    if(g.cycle())
    {
        cout<<"cycle is preset in undirected graph"<<endl;
    }
    else
    {
        cout<<"cycle is not present"<<endl;
    }
    
}