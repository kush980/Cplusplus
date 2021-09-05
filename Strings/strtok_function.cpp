#include<iostream>
#include<string>
#include<cstring>
using namespace std;
char *mystrtok(char *s, char delim)
{
    static char *input=NULL;
    if(s!=NULL)
    {
        input = s;      //first call to the arguement
    }
    if(input==NULL)
    {
        return NULL;
    }
    //now for subsequent calls , start extracting tokens and store them in an array
    char *output= new char[strlen(input)+1];
    int i=0;
    for(;input[i]!='\0';i++)
    {
        if(input[i]!=delim)
        {
            output[i]=input[i];
        }
        else
        {
            output[i]='\0';
            input+=i+1;
            return output;
        }
     }
     //last case
     output[i]='\0';
     input=NULL;
     return output;
}
int main()
{
    //using mystrtok func
    char s[100] = "i am awesome";
   char *a= mystrtok(s,' ');
   cout<<a<<endl;
   while(a!=NULL)
   {
       a=mystrtok(NULL,' ');
       cout<<a<<endl;
   }
   return 0;
}