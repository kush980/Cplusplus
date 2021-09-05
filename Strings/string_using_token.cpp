#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
    //char *strtok(char s,char ,delimeter)
    // return subsequent token on each call
    // on first call func should should be passed with arguement s
    // on subsequent calls function needs to be passed with null
    char s[100] = "i am awesome";
   char *a= strtok(s," ");
   cout<<a<<endl;
   while(a!=NULL)
   {
       a=strtok(NULL," ");
       cout<<a<<endl;
   }
   return 0;
}