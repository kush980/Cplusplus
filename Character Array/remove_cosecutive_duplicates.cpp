#include<iostream>
#include<cstring>
using namespace std;
void remove(char a[])
{
    int j=strlen(a);
    if(j==1 || j==0)
    {
        return;
    }
        int i=0;
        for(int cur=1;cur<j;cur++)
        {
            if(a[i]!=a[cur]){
            i++;
            a[i]=a[cur];
        }
    }
    a[i+1]='\0';
}
int main()
{
    char a[1000];
    cin.getline(a,1000);
    remove(a);
    cout<<a<<endl;

}