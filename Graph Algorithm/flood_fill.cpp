#include<iostream>
using namespace std;

int R;
int C;

void print(char input[][50])
{
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cout<<input[i][j];
        }
        cout<<endl;
    }
}

//W,N,E,S
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};

void flood_fill(char input[][50],int i,int j,char ch,char color)
{
    //base case
    if(i<0||j<0 ||i>=R||j>=C)
    {
        return;
    }
    //filling boundary condition
    if(input[i][j]!=ch)
    {
        return;
    }

    //recursive case
    input[i][j]=color;

    for(int k=0;k<4;k++)
    {
        flood_fill(input,i+dx[k],j+dy[k],ch,color);
    }

}

int main()
{
    cin>>R>>C;
    char input[20][50];
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            cin>>input[i][j];
        }
    }
    print(input);

    flood_fill(input,8,13,'.','r');
    print(input);

}