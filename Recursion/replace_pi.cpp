#include<iostream>
using namespace std;

void replacepi(char a[],int i)
{
    //base case
    if(a[i]=='\0'||a[i+1]=='\0')
    return;
    
    //search "pi"
    if(a[i]=='p' and a[i+1]=='i')
    {
        int j=i+2;
        while(a[j]!='\0')
        {
            j++;
        }
        while(j>=i+2)
        {
            a[j+2]=a[j];
            j--;
        }
        a[i]='3';
        a[i+1]='.';
        a[i+2]='1';
        a[i+3]='4';
        replacepi(a,i+4);
    }
    else
    {
        replacepi(a,i+1);
    }
    return;
}

int main()
{
    char a[100];
    cin>>a;
    replacepi(a,0);
    cout<<a<<endl;
    return 0;
}