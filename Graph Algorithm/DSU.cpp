#include<iostream>
#include<list>
using namespace std;

class graph
{

    int V;
    list<pair<int,int> > l;
public:

    graph(int V)
    {
        this->V = V;
    }

    void addEdge(int u,int v)
    {
        l.push_back(make_pair(u,v));
    }

    int find_set(int i,int parent[])
    {
        if(parent[i]==-1)
        {
            return i;
        }

        return find_set(parent[i],parent);
    }

    void union_set(int x,int y,int parent[])
    {
        int s1 = find_set(x,parent);
        int s2 = find_set(y,parent);

        if(s1!=s2)
        {
            parent[s1]=s2;
        }
    }

    bool contain_cycle()
    {
        int *parent = new int[V];
        for(int i=0;i<V;i++)
        {
            parent[i]=-1;
        }

        for(auto edge : l)
        {
            int i = edge.first;
            int j = edge.second;

            int s1 = find_set(i,parent);
            int s2 = find_set(j,parent);

            if(s1!=s2)
            {
                union_set(s1,s2,parent);   
            }
            else
            {
                cout<<"Same parents "<<s1<<" and "<<s2<<endl;
                return true;
            }
        }
        delete []parent;;
        return false;
    }
};


int main()
{
    graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);

    cout<<g.contain_cycle()<<endl;
}