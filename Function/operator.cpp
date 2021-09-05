#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    cout<<"and"<<(a&b)<<endl;
    cout<<"or"<<(a|b)<<endl;
    cout<<"xor"<<(a ^ b)<<endl;
    cout<<"shift"<<(a>>1)<<endl;
}