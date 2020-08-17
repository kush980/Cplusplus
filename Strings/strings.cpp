#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s0;
    string s1="yo yo";
    string s2="this is kushagr";
    string s3(s2);
    string s4=s3;
    char a[]={'a','b','c','\0'};
    string s5=a;
    cout<<s0<<endl;
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    cout<<s4<<endl;
    cout<<s5<<endl;
    // add characters
    s0.append("i love coding");
    cout<<s0<<endl;
    s0+=" and machine learning too";
     cout<<s0<<endl;
     // remove characters
     cout<<s0.length()<<endl;
     s0.clear();
     cout<<s0.length()<<endl;
     
     //compare 2 strings 
     s0="physics";
     s1="computer science";
     cout<<s0.compare(s1)<<endl; // if equal then returns 0 otherwise >0 or <0 , depends on lexicographical order

     //overload operator operators
     if(s0>s1)
     cout<<"physics is lexicographically greater than computer science"<<endl;

     cout<<s2[0]<<endl;
    
    //find substring 
    string s= "I am fucking awesome ";
    int index=s.find("fucking");
    cout<<index<<endl;

    //remove a word from the string 
    string remove_word="fucking";
    cout<<s<<endl;
    int len=remove_word.length();
    s.erase(index,len+1); //+1 , to remove the extra space too
    cout<<s<<endl;

    //iterate over all the characters in the string 
    for(int i=0;i<s1.length();i++)
    {
        cout<<s1[i]<<":";
    }
    cout<<endl;
    //iterator 
    for(auto it=s1.begin();it<s1.end();it++)   //auto defines the datatype by itself whether its int or string or any other datatype
   //a;ternative for auto over here will be string::iterator
    {
        cout<<(*it)<<",";   //it works as a pointer so the value at that address will be printed
    }
    cout<<endl;
    //iterate for eacj loop works in c++ 11
    for(char c:s1)
    {
        cout<<c<<":";
    }
    cout<<endl;

}