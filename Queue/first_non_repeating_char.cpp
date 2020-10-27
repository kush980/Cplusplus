#include<iostream>
#include<queue>
using namespace std;

int main()
{
    queue<char> q;
    int freq[26]={0};
    char ch;
    cin>>ch;

    while(ch!='.')
    {
        //logic will be here
        q.push(ch);
        freq[ch-'a']++;
        while(!q.empty())
        {
            int idx_ele=q.front()-'a';
            if(freq[idx_ele]>1)
            {
                q.pop();
            }
            else
            {
                cout<<q.front()<<endl;
                break;
            }
            
        }

        if(q.empty())
        {
            cout<<-1<<endl;
        }
        cin>>ch;
    }

    return 0;
}