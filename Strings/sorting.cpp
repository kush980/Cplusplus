#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool compare (string a,string b)  //to compare on the  basis of length of string 
{
    if(a.length()==b.length())
    {
        return a<b;   //if length is same then compare lexicographically
    }
    return a.length()>b.length(); //otherwise return on the basis of length  
}
int main()
{
    int n;
    cin>>n;
    cin.get();
    string s[100];
    for(int i=0;i<n;i++)
    {
        getline(cin,s[i]);      //in string getline function has to be used under loop
    }
    sort(s,s+n,compare);
    for(int i=0;i<n;i++)
    {
        cout<<s[i]<<endl;
    }
}