#include<iostream>
#include<stack>
using namespace std;


int getmaxArea(int hist[],int n)
{
    stack<int> s;
    int max_area=0;
    int tp;
    int area_top;

    //run through all bars of the given histogram
    int i=0;
    while(i<n)
    {
        if(s.empty() || hist[s.top()]<=hist[i])
        {
            s.push(i);
            i++;
        }
        else
        {
            tp=s.top();
            s.pop();

            area_top=hist[tp]*(s.empty()? i:i-s.top()-1);

            //update the maximum area
            if(max_area<area_top)
            {
                max_area=area_top;
            }
        }
        
    }

    //now remove the remaining bars from the stack
    while(s.empty()==false)
    {
        tp=s.top();
        s.pop();

        area_top=hist[tp]*(s.empty()?i:i-s.top()-1);

        if(max_area<area_top)
        {
            max_area=area_top;
        }
    }
    return max_area;
}

int main()
{
    int n;
    cin>>n;

    int hist[n];
    for(int i=0;i<n;i++)
    {
        cin>>hist[i];
    }
    cout<<getmaxArea(hist,n)<<endl;

    return 0;
}