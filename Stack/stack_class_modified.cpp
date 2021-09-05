#include<iostream>
#include<vector>
using namespace std;


class stack
{
private:
    vector<int> v;
    vector<int> v_min;
    vector<int> v_max;
public:
    void push(int data)
    {
        int current_min=data;
        int current_max=data;
        if(v_min.size())
        {
            current_min=min(v_min[v_min.size()-1],data);
            current_max=max(v_max[v_max.size()-1],data);
        }
        v_min.push_back(current_min);
        v_max.push_back(current_max);
        v.push_back(data);
    }

    bool empty()
    {
        return v.size()==0;
    }

    void pop()
    {
        v_max.pop_back();
        v_min.pop_back();
        v.pop_back();
        
    }

    int top()
    {
        return v[v.size()-1];
    }

    int get_max()
    {
        return v_max[v_max.size()-1];
    }

    int get_min()
    {
        return v_min[v_min.size()-1];
    }

};

int main()
{
    stack s;
    s.push(1);
    s.push(5);
    s.push(3);
    s.push(8);

    cout<<s.top()<<endl;
    cout<<s.get_max()<<endl;
    s.pop();
    cout<<s.get_min()<<endl;
    cout<<s.get_max()<<endl;
    s.pop();
    s.pop();
    cout<<s.get_max()<<endl;

    return 0;
}