#include<iostream>
#include<set>
#include<vector>
using namespace std;

class point
{
public:
    int x,y;
    point()
    {

    }
    point(int x,int y)
    {
        this->x=x;
        this->y=y;
    }
};

class compare
{
public:
    bool operator()(point p1,point p2)
    {
        if(p1.x==p2.x)
        return p1.y<p2.y;
        return p1.x<p2.x;
    }
};

int countRectangle(vector<point> coords)
{
   // int N = coords.size();

    set<point,compare> s;
    for(auto p:coords)
    {
        s.insert(p);
    }

    int ans=0;

    //2 loops
    for(auto it=s.begin();it!=prev(s.end());it++)
    {
        for(auto jt=next(it);jt!=s.end();jt++)
        {
            point p1=*it;
            point p2=*jt;
            //checking conditions
            if(p2.x==p1.x or p2.y==p1.y)
            continue;

            point p3(p1.x,p2.y);
            point p4(p2.x,p1.y);
            if(s.find(p3)!=s.end() and s.find(p4)!=s.end())
            ans++;
        }
    }
    return ans/2;   
}

int main()
{
    int n;
    cin>>n;
    vector<point> coords;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        point p(x,y);
        coords.push_back(p);
    }
    cout<<countRectangle(coords)<<endl;
}