#include<iostream>
#include<map>
#include<queue>
#include<list>
#include<climits>
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

    void bfs (T src)
    {
        map<T,int> dist;
        queue<T> q;

        for(auto node_pair:l)
        {
            T node = node_pair.first;
            dist[node] = INT_MAX;

        }  
        q.push(src);
        dist[src] = 0;

        while(!q.empty())
        {
            T node = q.front();
            q.pop();

           // cout<<node<<" ";

            for(int nbr:l[node])
            {
                if(dist[nbr]==INT_MAX)
                {
                    q.push(nbr);
                    //mark this as visited

                    dist[nbr] = dist[node] + 1;
                }
            }

        }

        for(auto node_pair:l)
        {
            T node = node_pair.first;
            int d = dist[node];

            cout<<"Node "<<node<<" Dist from src "<<d<<endl;
        }
    }

};


int main()
{
    graph<int> g;

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.bfs(0);

}