#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main()
{
    unordered_map<string , vector<string>> phonebook;

    phonebook["Nikhil"].push_back("1234");
    phonebook["Nikhil"].push_back("1224");
    phonebook["Nikhil"].push_back("1334");
    phonebook["Nikhil"].push_back("1534");
    phonebook["Nikit"].push_back("2345");
    phonebook["Nikit"].push_back("2342");
    phonebook["Nikit"].push_back("2341");

    for(auto p:phonebook)
    {
        cout<<"Name "<<p.first<<"->";
        for(auto s:p.second)
        {
            cout<<s<<",";
        }
        cout<<endl;
    }

    string name;
    cin>>name;

    if(phonebook.count(name)==0)
    {
        cout<<"No nummber";
    }
    else
    {
        for(string s:phonebook[name])
        cout<<s<<endl; 
    }
    
}