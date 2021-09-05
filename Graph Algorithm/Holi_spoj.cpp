#include<iostream>
#include<list>
#define ll long long
using namespace std;

class graph
{

    list<pair<ll,ll>> *l;
    int V;
public:

    graph(ll v)
    {
        V=v;
        l = new list<pair<ll,ll>>[V];
    }

    void addEdge(ll u,ll v,ll cost)
    {
        l[u].push_back(make_pair(v,cost));
        l[v].push_back(make_pair(u,cost));
    }
    
    ll dfs_helper(ll node,bool *visited,ll *count,ll &ans)
    {
        //mark the node as visited and increment the count
        visited[node] = true;
        count[node] = 1;

        for(auto nbr_pair:l[node])
        {
            ll nbr = nbr_pair.first;
            ll wt = nbr_pair.second;
            if(!visited[nbr])
            {
                count[node]+=dfs_helper(nbr,visited,count,ans);
                ll nx = count[nbr];
                ll ny = V-nx;
                ans+=2*min(nx,ny)*wt;
            }
        }
        return count[node];
    }

    ll dfs()
    {
        bool *visited = new bool[100001]{0};
        ll *count = new ll[100001]{0};

        for(int i=0;i<V;i++)
        {
            visited[i]=false;
            count[i]=0;
        }
        ll ans=0;
        dfs_helper(0,visited,count,ans);
        return ans;
    }

};

int main()
{
    int t;
    cin>>t;
    int temp = 1;
    while(t)
    {
        ll n;
        cin>>n;
        graph g(n);
        for(ll i=1;i<n;i++)
        {
            ll u,v,wt;
            cin>>u>>v>>wt;
            g.addEdge(u-1,v-1,wt);
        }
            cout<<"Case #"<<temp<<": "<<g.dfs()<<endl;
            temp++;
            t--;
    }
}