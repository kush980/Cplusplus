#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class student
{
public:
    string firstname;
    string lastname;
    string rollno;

    student(string f,string l,string no)
    {
        firstname = f;
        lastname = l;
        rollno = no;
    }

    bool operator==(const student &s) const
    {
        return rollno == s.rollno ;
    }
};

class hashfn
{
    public:
        size_t operator()(const student &s) const {
            return s.firstname.length() + s.lastname.length();
        }
};

int main()
{
    unordered_map<student,int,hashfn> student_map;

    student s1("Kushagr","Singh","107");
    student s2("Nikhil","Dubey","34");
    student s3("Sanskar","Gupta","109");
    student s4("Sanskar","Singh","45");

    student_map[s1] = 190;
    student_map[s2] = 100;
    student_map[s3] = 80;
    student_map[s4] = 11;

    //operator use
    cout<<"Marks of "<<s3.firstname<<" "<<student_map[s3]<<endl;

    for(auto s:student_map)
    {
        cout<<s.first.firstname<<" "<<s.first.rollno<<endl<<"Marks "<<s.second<<endl;
    }
}