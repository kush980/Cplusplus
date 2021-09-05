#include<iostream>
#include<unordered_map>
#include<list>
#include<cstring>
using namespace std;

class Graph
{

    unordered_map<string,list<pair<string,int> > > l;
public:
    void addEdge(string x,string y,bool dir,int wt)
    {
        l[x].push_back(make_pair(y,wt));
        if(dir)
        {
            l[y].push_back(make_pair(x,wt));
        }
    }

    void print()
    {
        for(auto p:l)
        {
            string s = p.first;
            list<pair<string,int> > s2 = p.second;

            cout<<p.first<<" -> ";
            for(auto o:s2)
            {
                string d = o.first;
                int d2 = o.second;

                cout<<d<<" "<<d2<<",";
            }
            cout<<endl;
        }
        
    }


};

int main()
{
    Graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("B","D",true,40);
    g.addEdge("A","C",true,10);
    g.addEdge("C","D",true,40);
    g.addEdge("A","D",false,50);

    g.print();
}
