#include<iostream>
#include<cstring>
using namespace std;
bool palindrom(char a[])
{
    int i=0;
    int j=strlen(a)-1;
    while(i<j)
    {
        if(a[i]==a[j])
        {
            i++;
            j--;
        }
    else 
    return false;
    }
    return true;
}
int main()
{
    char a[1000];
    cin.getline(a,1000);
    if(palindrom(a))
    cout<<"palindromic string"<<endl;
    else
    {
        cout<<"its not a palindromic string"<<endl;
    }
}