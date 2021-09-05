#include<iostream>
#include<list>
#include<map>
using namespace std;

template<typename T>
class graph
{

    map<T,list<T>> l;
public:

    void addEdge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);      //considering the graph is bidirectional
    }

    void dfs_helper(T src,map<T,bool> &visited)
    {
        cout<<src<<" ";
        visited[src] = true;        // vry imp
        for(T nbr:l[src])
        {
            if(!visited[nbr])
            {
                dfs_helper(nbr,visited);
            }
        }
    }


    void dfs(T src)
    {
        map<T,bool> visited;

        for(auto p:l)
        {
            T node = p.first;
            visited[node] = false;
        }

        //call the helper/recursive function
        dfs_helper(src,visited);
    }


};

int main()
{
    graph<int> g;

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);

    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(3,0);

    g.dfs(0);
}