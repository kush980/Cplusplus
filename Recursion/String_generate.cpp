#include<iostream>
using namespace std;

void string_generate(char *in,char *out,int i,int j)
{
    //base case
    if(in[i]=='\0')
    {
        out[j]='\0';
        cout<<out<<endl;
        return ;
    }
    //rec case
    //taking one digit at a time        (won't work for zero)
    int digit = in[i]-'0';
    // if(digit==0)
    // {
    //     int zero=in[i-1]-'0';
    //     int no_2=zero*10+digit;
    //     if(no_2<=26)
    //     {
    //         char ch_z=no_2+'A'-1;
    //         out[j]=ch_z;
    //         string_generate(in,out,i+1,j+1);
    //     }
    // }
    char ch = digit+'A'-1;
    out[j]=ch;
    string_generate(in,out,i+1,j+1);

    //taking two digit at a time
    if(in[i+1]!='\0')
    {
        int seconddigit=in[i+1]-'0';
        int no = digit*10 + seconddigit;
        if(no<=26)
        {
            ch=no+'A'-1;
            out[j]=ch;
            string_generate(in,out,i+2,j+1);
        }
    }
    return;
}

int main()
{
    char in[100];
    cin>>in;

    char out[100];
    string_generate(in,out,0,0);
}