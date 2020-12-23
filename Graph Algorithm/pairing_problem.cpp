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

        return parent[i]=find_set(parent[i],parent);
    }

    void union_set(int x,int y,int parent[],int rank[])
    {
        int s1 = find_set(x,parent);
        int s2 = find_set(y,parent);

        if(s1!=s2)
        {
            if(rank[s1]<rank[s2])
            {
                parent[s1] = s2;
                rank[s2]+=rank[s1];
            }
            else
            {
                parent[s2]=s1;
                rank[s1]+=rank[s2];
            }
        }
    }
    int pairing()
    {
        int *parent = new int[V];
        int *rank = new int[V];

        for(int i=0;i<V;i++)
        {
            parent[i]=-1;
            rank[i]=1;
        }

        for(auto edge:l)
        {
            int i=edge.first;
            int j=edge.second;

            int s1=find_set(i,parent);
            int s2=find_set(j,parent);

            union_set(s1,s2,parent,rank);

        }

        int ans=0;
        for(int i=0;i<V;i++)
        {
            ans+=V - rank[find_set(i,parent)];
        }

        return ans/2;
    }
    
};

int main()
{
    int n,m;
    cin>>n>>m;
    graph g(n);
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        g.addEdge(x,y);

    }

    cout<<g.pairing()<<endl;

}