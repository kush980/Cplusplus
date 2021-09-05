#include<iostream>
using namespace std;

void hanoi(int n,char src,char helper,char dest)
{
    //base case
    if(n==0)
    return;

    //rec case
    hanoi(n-1,src,dest,helper);
    cout<<"Shift disk "<<n<<" from "<<src<<" to "<<dest<<endl;
    hanoi(n-1,helper,src,dest);
}

int main()
{
    int n;
    cin>>n;
    hanoi(n,'A','B','C');
}