#include<iostream>
#include<string>
#include<cstring>
using namespace std;


//access specifiers - public & private 

//defining a new datatype
class Car{
private:
    float price;        //removes the access of read and write 
public:
    int model_no;
    char name[20];

    //constructor
    Car()
    {
        cout<<"inside the constructor"<<endl;
    }
    //if one have more than one constructor in a program , its called constructor overloading as the name of all the constructor will be same as the name of the Class.
    //parameterised constructor
    Car(float p,int m,char *n)
    {
        price = p;
        model_no=m;
        strcpy(name,n);
    }

    //Copy Constructor
    Car(Car &x)
    {
        cout<<"Copy Constructor"<<endl;
        price=x.price;
        model_no=x.model_no;
        strcpy(name,x.name);
    } 

    void print()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Model No.: "<<model_no<<endl;
        cout<<"Price: "<<price<<endl;       //can only access the prive in the class datatype 
    }

    float apply_discount(float x){
        price=price*(1.0-x);
        return price;
    }
    void set_price(float p)     //can access the price in the Car class datatype only
    {
        float msp=140;
        if(p>0)
        price=p;
        else
        price=msp;
    }

    float get_price()   //can show the price i.e gives the access of read 
    {
        return price;
    }
};

int main()
{
    Car c;
    Car d(122,1432,"Mercedes");
    cout<<"CAR D"<<endl;
    d.print();
   // c.price=100;
    cout<<"CAR E"<<endl;
    Car e(d);   //calling copy constructor of my own 
    Car f = e; //another way of calling the copy constructor 
    e.set_price(390);
    e.print();
   

    c.model_no=124;
    c.name[0]='A';
    c.name[1]='U';
    c.name[2]='D';
    c.name[3]='I';
    c.name[4]='\0';

    // cout<<"Name "<<c.name<<" Model No "<<c.model_no<<" Price "<<c.price;
    c.set_price(100);
    cout<<"Before Applying Discount"<<endl;
    c.print();

    float discount;
    cin>>discount;

    c.apply_discount(discount);
    cout<<"After applying discount"<<endl;
    c.print();

    return 0;

}