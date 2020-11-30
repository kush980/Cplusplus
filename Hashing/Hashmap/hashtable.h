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

    void rehash()
    {
        node<T>**oldTable = table;
        int oldTablesize = table_size;
        table_size = 2*table_size;
        table = new node<T>*[table_size];

        for(int i=0;i<table_size;i++)
        {
            table[i]=NULL;
        }
        current_size = 0;
        //move the elements form oldtable to new table -> rehashing
        for(int i=0;i<oldTablesize;i++)
        {
            node<T>*temp = oldTable[i];
            while(temp!=NULL)
            {
                insert(temp->key,temp->value);
                temp = temp->next;
            }
            if(oldTable[i]!=NULL)
            {
                delete oldTable[i];
            }
        }

        delete [] oldTable;
    }

public:
    Hashtable(int ts=7)
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
        
        node<T>*n = new node<T>(key,value);
        //insert at the head of the linked list id=idx
        n->next = table[idx];
        table[idx] = n;
        current_size++;

        float load_factor = current_size/(1.0*table_size);
        if(load_factor>0.7)
        {
            rehash();
        }
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