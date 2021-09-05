#include<iostream>
#include<list>
using namespace std;


//we will create a function using iterators which will help in all the sequential datatypes i.e. vectors,list,others . 

template<class ForwardIterator,class T>
ForwardIterator search(ForwardIterator start,ForwardIterator end,T key)
{
    while(start!=end)
    {
        if(*start==key)
        return start;
        start++;
    }
    return end;
}

int main()
{
    //using list here , can use other sequential datatypes too
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(5);

    auto it=search(l.begin(),l.end(),3);
    if(it==l.end())
    cout<<"element not present"<<endl;
    else
    {
        cout<<*it<<endl;
    }
    
}