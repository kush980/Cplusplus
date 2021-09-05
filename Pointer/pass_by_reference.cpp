#include<iostream>
using namespace std;
    //pass by value
    void increment(int a){
    a=a+1;
    cout<<"pass by value :"<<a<<endl;
}
//pass by reference
void increment_2(int *aptr)
{
    *aptr+=1;
    cout<<"pass by reference :"<<*aptr<<endl;
}
    int main()
    {
        int a;
        a=10;
        increment(a);
        increment_2(&a);
        cout<<"inside main :"<<a<<endl;     //incremented bcoz of pass by reference 
    }