#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
string extractatkey(string s,int key)
{
    char*str=strtok((char *)s.c_str()," ");
    while(key>1)
    {
        str=strtok(NULL," ");
        key--;
    }
    return (string)str;
}
int converttoint(string s)
{
    int ans=0;
    int p=1;
    for(int i=s.length();i>=0;i--)
    {
        ans+=((s[i]-'0')*p);
        p=p*10;
    }
    return ans;
}
bool numericcomp(pair<string,string>s1,pair<string,string>s2)
{
    string key1,key2;
    key1=s1.second;
    key2=s2.second;
    return converttoint(key1)<converttoint(key2);
}
bool lexicomp(pair<string,string>s1,pair<string,string>s2)
{
    string key1,key2;
    key1=s1.second;
    key2=s2.second;
    return key1<key2;
}
int main()
{
    int n;
    cin>>n;
    cin.get();
    string a[100];
    for(int i=0;i<n;i++)
    {
        getline(cin,a[i]);
    }
    int key;
    string reverse,order;
    cin>>key;
    cin>>reverse>>order;
    pair<string,string> str[100];
    for(int i=0;i<n;i++)
    {
    str[i].first=a[i];
    str[i].second=extractatkey(a[i],key);
    }
    if(order =="numeric")
    {
        sort(str,str+n,numericcomp);
    }
    else
    {
        sort(str,str+n,lexicomp);
    }
    if(reverse == "true")
    {
        for(int i=0;i<n/2;i++)
        {
            swap(str[i],str[n-i-1]);
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<str[i].first<<endl;
    }
    
}
