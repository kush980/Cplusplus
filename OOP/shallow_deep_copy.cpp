#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Car
{
private:
    float price;
public:
    int model_no;
    char *name;

    //constructor
    Car()
    {
        name = NULL;
    }

    Car(float p,int m,char *n)
    {
        price = p;
        model_no = m;
        name = new char[strlen(n)+1];
        strcpy(name,n);
    }

    Car(Car &x)
    {
        price=x.price;
        model_no=x.model_no;
        name = new char[strlen(x.name)+1];
        strcpy(name,x.name);
    }

    void print()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Model No.: "<<model_no<<endl;
        cout<<"Price: "<<price<<endl;       //can only access the prive in the class datatype 
    }

    void set_price(float p)
    {
        price =p;
    }

};
int main()
    {
        Car c(100,200,"Tesla");
        Car d(c);       //using inbuilt copy constructor

        d.name[0]='A';      //now in this the name of class Car c is also getting changed which is called shallow copy , to overcome this we need to create our own copy constructor as deep copy.
        d.set_price(400);
        c.print();
        d.print();
    }