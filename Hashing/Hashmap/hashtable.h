#include<iostream>
#include<string>
using namespace std;

template<typename T>
class node
{
    public:
        string key;
        T value;
        node<T>*next;

        node(string key,T val)
        {
            this->key = key;
            value = val;
            next = NULL;
        }
        ~node()
        {
            if(next!=NULL)
            {
                delete next;
            }
        }
};
template<typename T>
class Hashtable
{
    
    node<T>**table;
    int table_size;
    int current_size;

    int hashFn(string key)
    {
        int idx = 0;
        int p=1;
        for(int j=0;j<key.length();j++)
        {
            idx = idx+(key[j]*p)%table_size;
            idx = idx%table_size;
            p = (p*27)%table_size;
        }
        return idx;
    }

public:
    Hashtable(int ts=10)
    {
        table_size=ts;
        table = new node<T>*[table_size];
        current_size = 0;
        for(int i=0;i<table_size;i++)
        {
            table[i]=NULL;
        }
    }
    void insert(string key , T value)
    {
        int idx = hashFn(key);
        
        node<T>*n = new node<T>(key,val);
        //insert at the head of the linked list id=idx
        n->next = table[idx];
        table[idx] = n;
        current_size++;
    }

    void print()
    {
        for(int i=0;i<table_size;i++)
        {
            cout<<"Bucket "<<i<<"->";
            node<T>*temp = table[i];
            while(temp!=NULL)
            {
                cout<<temp->key<<"->";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
};