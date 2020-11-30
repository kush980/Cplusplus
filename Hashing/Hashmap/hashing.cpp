#include<iostream>
#include"hashtable.h"
using namespace std;

int main()
{
    Hashtable<int> price_menu;

    price_menu.insert("Burger",120);
    price_menu.insert("Pepsi",20);
    price_menu.insert("BurgerPizza",150);
    price_menu.insert("Noodles",25);
    price_menu.insert("Coke",50);

    price_menu.print();
    int *price = price_menu.search("Burger");
    if(price==NULL)
    {
        cout<<"Item not Present"<<endl;
    }
    else
    {
        cout<<"The price is: "<<*price<<endl;
    }
    
    //insert
    price_menu["Soup"] = 100;
    //update
    price_menu["Soup"]+= 20;
    //printing
    cout<<"The price is: "<<price_menu["Soup"]<<endl;  
}