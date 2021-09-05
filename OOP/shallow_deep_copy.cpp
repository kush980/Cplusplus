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

    Car(Car &x)             //deep function of copy constructor
    {
        price=x.price;
        model_no=x.model_no;
        name = new char[strlen(x.name)+1];
        strcpy(name,x.name);
    }

    Car operator= (Car &x)              //deep function of copy assignment operator
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

    ~Car()          //this destructor is not needed to be created when static memory is used and it works in reverse order as we can see in the output.
    {
        cout<<"deleting car "<<name<<endl;
        if(name!=NULL)
        {
            delete [] name;
        }
        
    }

};
int main()
    {
        Car c(100,200,"Tesla");
        //Car d(c);       //using inbuilt copy constructor
        Car d;
        d=c;    //using inbuilt copy assignment operator and it can be called as many times we want unlike constructor, this will also give shallow copy so we will make a deep copy function.
        d.name[0]='A';      //now in this the name of class Car c is also getting changed which is called shallow copy , to overcome this we need to create our own copy constructor as deep copy.
        d.set_price(400);
        c.print();
        d.print();

        Car *e=new Car(10,30,"BMW");
        e->print();     //it is a method to print dynamically created object.

        delete e;       //this way we have to delete dynamically created objects.

    }