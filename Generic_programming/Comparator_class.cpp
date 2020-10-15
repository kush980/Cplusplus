#include<iostream>
#include<vector>
using namespace std;


class Book {
public:
    string name;
    int price;

    Book()
    {

    }

    Book(string name,int price)
    {
        this->name=name;
        this->price=price;
    }

};

class BookCompare{
public:
    bool operator()(Book A,Book B)
    {
        if(A.name==B.name)
        return true;
        return false;
    }


};

template<class ForwardIterator,class T,class Compare>
ForwardIterator search(ForwardIterator start,ForwardIterator end,T key,Compare cmp)
{
    while(start!=end)
    {
        if(cmp(*start,key))
        return start;
        start++;
    }
    return end;
}

int main()
{
    Book a("C++",100);
    Book b("Java",220);
    Book c("Python",300);

    vector<Book> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);

    Book Find("C++",110);
    BookCompare cmp;

    auto it=search(v.begin(),v.end(),Find,cmp);
    if(it!=v.end())
    cout<<"Book found in the library";

    else
    {
        cout<<"Not found";
    }
    

}