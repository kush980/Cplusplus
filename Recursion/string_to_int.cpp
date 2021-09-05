#include<iostream>
#include<string>
#include<cstring>
using namespace std;



int stringtoint(char *a,int n)
{
    if(n==0)
    return 0;
    int digit=a[n-1]-'0';
    int small_ans=stringtoint(a,n-1);

    return small_ans*10+digit;
}

int main()
{
    char a[]="2048";
    int len=strlen(a);
    int x=stringtoint(a,len);
    cout<<x<<endl;
    cout<<x+1<<endl;

}


