#include<iostream>
using namespace std;
//function to read the whole paragraph instead of just a word or the mechanism of inbuilt function getline.
void readline(char a[],int max,char stop='\n')
{
    int i=0;
    char ch=cin.get();
    while(ch!=stop)
    {
        a[i]=ch;
        i++;
        if(i==max-1)
        break;
        ch=cin.get();
    }
    //once out of the loop 
    a[i]='\0';
    return;
    
}
int main()
{
    char a[1000];
   // readline(a,1000);
    cin.getline(a,1000,'\n');   //this is the inbuilt function we can use instead of the whole function
    cout<<a<<endl;
}