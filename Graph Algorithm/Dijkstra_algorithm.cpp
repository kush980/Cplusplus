#include<bits/stdc++.h>
using namespace std;


template<typename T>
class graph
{

    unordered_map<T,list<pair<T,int>>> m;
public:
    void addEdge(T u,T v,int dist,bool bidir = true)
    {
        m[u].push_back(make_pair(v,dist));
        if(bidir)
        {
            m[v].push_back(make_pair(u,dist));
        }
    }

    void printAdj()
    {
        for(auto j:m)
        {
            cout<<j.first<<"--> ";
            for(auto l:j.second)
            {
                cout<<"("<<l.first<<","<<l.second<<") ";
            }
            cout<<endl;
        }
    }

    void dijkstra(T src)
    {
        unordered_map<T,int> dist;
        
        //set all distances to infinity
        for(auto j:m)
        {
            dist[j.first]=INT_MAX;
        }

        //make a set to find out node with minimum distance
        set<pair<int,T>> s;
        dist[src]=0;
        s.insert(make_pair(0,src));

        while(!s.empty())
        {

            //find the pair at the front
            auto p = *(s.begin());
            T node = p.second;

            int nodeDist = p.first;
            s.erase(s.begin());

            //iterate over children/neghbour of the current node
            for(auto child : m[node])
            {
                if(nodeDist + child.second < dist[child.first])
                {

                    //In set , updation is not possible 
                    //so we will remove the element and insert the new pair for updation

                    T dest = child.first;
                    auto f = s.find(make_pair(dist[dest],dest));
                    if(f!=s.end())
                    {
                        s.erase(f);
                    }

                    //insert the new pair
                    dist[dest] = nodeDist + child.second;
                    s.insert(make_pair(dist[dest],dest));

                }
            }

        }
        for(auto l:dist)
        {
            cout<<l.first<<" is located at a distance of "<<l.second<<endl;
        }
    }

};


int main()
{
    
    graph<int> g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
    //g.printAdj();
    g.dijkstra(1);
    /*
    graph<string> india;
    india.addEdge("Amritsar","Delhi",1);
    india.addEdge("Amritsar","Jaipur",4);
    india.addEdge("Jaipur","Delhi",2);
    india.addEdge("Jaipur","Mumbai",8);
    india.addEdge("Bhopal","Agra",2);
    india.addEdge("Mumbai","Bhopal",3);
    india.addEdge("Agra","Delhi",1);
    //india.printAdj();
    india.dijkstra("Amritsar");
    */
}