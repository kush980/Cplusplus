#include<iostream>
#include<cstring>
using namespace std;

class fun
{
    public:
        void operator()(string s)
        {
            cout<<"Having fun inside operator with "<<s;
        }
};

int main()
{
    fun f;
    f("c++");   //overloaded () operator = function call in the fun class
}
