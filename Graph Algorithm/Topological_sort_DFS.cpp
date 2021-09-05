#include<iostream>
#include<list>
#include<map>
#include<cstring>
using namespace std;

template<typename T>
class graph
{

    map<T,list<T>> l;
public:

    void addEdge(T x,T y)
    {
        l[x].push_back(y);
        // l[y].push_back(x);      //considering the graph is bidirectional
    }

    void dfs_helper(T src,map<T,bool> &visited,list<T> &ordering)
    {
        // cout<<src<<" ";
        visited[src] = true;        // vry imp
        for(T nbr:l[src])
        {
            if(!visited[nbr])
            {
                dfs_helper(nbr,visited,ordering);
            }
        }

        ordering.push_front(src);
        return;
    }


    void dfs()
    {
        map<T,bool> visited;
        list<T> ordering;

        for(auto p:l)
        {
            T node = p.first;
            visited[node] = false;
        }

        //call the helper/recursive function
        for(auto p:l)
        {
            T node = p.first;
            if(!visited[node])
            {
                dfs_helper(node,visited,ordering);
            }
        }

        for(auto node:ordering)
        {
            cout<<node<<endl;
        }
    }


};

int main()
{
    graph<string> g;

    g.addEdge("Python","DataPreProcessing");
    g.addEdge("Python","Pythorch");
    g.addEdge("Python","ML");
    g.addEdge("DataPreProcessing","ML");
    g.addEdge("ML","DL");
    g.addEdge("DL","FaceRecogn");
    g.addEdge("Dataset","FaceRecogn");

    g.dfs();

    return 0;
}