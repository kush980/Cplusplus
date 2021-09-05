#include<iostream>
#include<unordered_map>
using namespace std;

class Node{
public:
    char data;
    int cnt;
    unordered_map<char,Node*> children;
    bool terminal;

    Node(char d){
        data=d;
        cnt=0;
        terminal=false;
    }
};

class Trie{
public:
    Node*root;
    Trie(){
        root=new Node('\0');
    }

    void insert(string s){
        Node*temp=root;
        
        for(int i=0;s[i]!='\0';i++){
            char ch=s[i];
            if(temp->children.count(ch)){
                temp=temp->children[ch];
                (temp->cnt)++;
            }
            else{
                Node*n=new Node(ch);
                temp->children[ch]=n;
                temp=n;
                (temp->cnt)++;
            }
        }
        temp->terminal=true;
    }

    bool find(string s){
        Node*temp=root;
        for(int i=0;s[i]!='\0';i++){
            char ch=s[i];
            if(temp->children.count(ch)==0){
                return false;
            }
            else{
                temp=temp->children[ch];
            }
        }
        return temp->terminal; // If the temp is terminal then return true
    }
};

string prefix(string s,Trie t)
{
    Node* temp = t.root;
    int i=0;
    int length = s.length();
    string ans="";
    while(i!=length)
    {
        if((temp->children[s[i]]->cnt)==1)
        {
            ans+=s[i];
            return ans;
        }
        else
        {
            ans+=s[i];
            temp = temp->children[s[i]];
        }
        i++;
        
    }
    ans="-1";
    return ans;
}

int main()
{
    Trie t;
    int n;
    cin>>n;
    string s[n];
    cin.get();
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        t.insert(s[i]);
    }
    for(int i=0;i<n;i++)
    {
        cout<<prefix(s[i],t)<<endl;
    }
    return 0;
}