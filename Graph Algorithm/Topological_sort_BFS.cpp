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
        //directed graph
        l[x].push_back(y);
    }

    void topological_sort()
    {
        //indegree
        int *indegree = new int[V];
        //setting the value to 0
        for(int i=0;i<V;i++)
        {
            indegree[i]=0;
        }

        for(int i=0;i<V;i++)
        {
            for(auto p:l[i])
            indegree[p]++;
        }

        //bfs
        queue<int> q;
        //1. find nodes with 0 indegree
        for(int i=0;i<V;i++)
        {
            if(indegree[i]==0)
            q.push(i);
        }

        //2. start removing elements from the queue
        while(!q.empty())
        {
            int node = q.front();
            cout<<node<<" ";
            q.pop();

            //3.iterate over the list and reduce indegree
            for(auto nbr:l[node])
            {
                indegree[nbr]--;
                if(indegree[nbr]==0)
                q.push(nbr);
            }
        }
    }

};


int main()
{
    graph g(6);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,3);
    g.addEdge(2,5);
    g.addEdge(3,5);
    g.addEdge(4,5);

    g.topological_sort();
}