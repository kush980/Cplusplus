#include<iostream>
using namespace std;

int *fun()
{
    int *a=new int [5];
    a[0]=100;
    a[1]=12;

    cout<<a<<endl;
    cout<<a[0]<<endl;

    //we cant return a local variable if its declared as static
    return a;  //but in here array is in heap section and the pointer is in the static
}

int main()
{
    int *b=fun();
    cout<<b<<endl;
    cout<<b[0]<<endl;
    delete[] b;
    return 0;

}
