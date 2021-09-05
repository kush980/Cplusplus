#include<iostream>
using namespace std;
int main()
{
    int a;
    int *aptr;
    a=10;
    aptr=&a;        //stores the address of int variable
    int x;
    x=20;
    cout<<&x<<endl;     //prints the address of int variable
    char b;
    b='a';
    cout<<(void *)&b<<endl;     //doesn't work on char variable , thus have to explicitly typecast from char* to void*
    char *c;
    int d;
    d=40;
    // c=&d;               //results in deferencing
    cout<<aptr<<endl;
    return 0;
}