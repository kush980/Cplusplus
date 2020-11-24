#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

class fun
{
    public:
        void operator()(string s)
        {
            cout<<"Having fun inside operator with "<<s;
        }
};

class person 
{
    public:
        string name;
        int age;
        person()
        {

        }
        person(string n,int a)
        {
            name = n;
            age = a;
        }
};

class personCompare         //STL only accepts class not functions
{
    public:
        bool operator()(person a,person b)
        {
            return a.age < b.age;
        }

};

int main()
{
    /*fun f;
    f("c++");   //overloaded () operator = function call in the fun class
    */

    int n;
    cin>>n;
    priority_queue<person , vector<person> , personCompare> pq; 
    for(int i=0;i<n;i++)
    {
        string name;
        int no;
        cin>>name>>no;
        person p(name,no);
        pq.push(p);
    }
    int k;
    cin>>k;

    for(int i=0;i<k;i++)        //here priority queue is best option considering time complexity
    {
        person p = pq.top();
        cout<<p.name<<" "<<p.age<<endl;
        pq.pop();
    }


}
