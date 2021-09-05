#include<iostream>
using namespace std;
int main()
{
    int x;
    int *xptr;
    x=10;
    xptr=&x;
    cout<<&x<<endl;
    cout<<xptr<<endl;

    cout<<*(&x)<<endl;
    cout<<*(xptr)<<endl;

    cout<<*(&xptr)<<endl;
    cout<<&(*xptr)<<endl;

    cout<<&xptr<<endl;
    //Double pointer
    int **xxptr=&xptr;
    cout<<xxptr<<endl;
    return 0;

}