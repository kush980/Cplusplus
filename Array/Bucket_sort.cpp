#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Students{
    public:
    int marks;
    string name;
};

void Bucket_sort(Students s[],int n)
{
    vector<Students> v[105];
    for(int i=0;i<n;i++)
    {
        int m=s[i].marks;
        v[m].push_back(s[i]);
    }

    for(int i=100;i>=0;i--)
    {
        for(vector<Students>::iterator it=v[i].begin();it!=v[i].end();it++)
        {
            cout<<(*it).marks<<" "<<(*it).name<<endl;
        }
    }
}

int main()
{
    Students s[10000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i].marks>>s[i].name;
    }
    Bucket_sort(s,n);
}
