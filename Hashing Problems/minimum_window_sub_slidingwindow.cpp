#include<iostream>
#include<climits>
#include<string>

using namespace std;

string find_window(string s,string p)
{
    int sl=s.length();
    int pl=p.length();

    //corner case
    if(pl>sl)
    return "Not possible";

    //freq maps
    int fs[256]={0};
    int fp[256]={0};

    for(int i=0;i<pl;i++)
    {
        char ch=p[i];
        fp[ch]++;
    }

    //sliding windows (expansion and contraction + updation of min length window)
    int cnt=0;
    int start=0;
    int min_len = INT_MAX;
    int start_idx=-1;
    for(int i=0;i<sl;i++)
    {
        char ch=s[i];
        fs[ch]++;

        //count of characters
        if(fp[ch]!=0 and fs[ch]<=fp[ch])
        {
            cnt++;
        }

        //contraction of length
        //when all char matched
        if(cnt==pl)
        {
            char temp = s[start];
            //to remove unwanted characters
            while(fp[temp]==0 or fs[temp]>fp[temp])
            {
                fs[temp]--;
                start++;
                temp = s[start];
            }

            //window size
            int window_len = i-start + 1;
            if(window_len<min_len)
            {
               min_len = window_len;
               start_idx = start;
            }
        }

    }
    if(start_idx==-1)
    return "Not Possible";

    string ans = s.substr(start_idx,min_len);
    return ans;

}

int main()
{
    string s,p;
    cin.ignore();
    getline(cin,s);
    getline(cin,p);

    cout<<find_window(s,p)<<endl;
}