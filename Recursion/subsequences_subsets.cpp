#include<iostream>
using namespace std;

void generate_subsequence(char *a,char *out,int i,int j)
{
    //base case
    if(a[i]=='\0')
    {
        out[j]=a[i];
        cout<<out<<endl;
        return;
    }
    //rec case
    //including the current element
    out[j]=a[i];
    generate_subsequence(a,out,i+1,j+1);

    //excluding the current element
    generate_subsequence(a,out,i+1,j);          //will be overwritten
}

int main()
{
    char a[]="abc";
    //cin>>a;
    char output[10];
    generate_subsequence(a,output,0,0);

}