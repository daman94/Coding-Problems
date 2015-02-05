//
//  main.cpp
//  Random classes oops lecture
//
//  Created by Daman Saroa on 31/12/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//

#include <iostream>
using namespace std;

/* class person {
    int age;
    char* name;
    bool sex;
public:
    person()
    {
        
    }
    
    person( char* n, int a, bool s) : name(n) , age(a) , sex(s)
    {
        
    }
    
    int getAge()
    {
        return age;
    }
    
    void setAge(int a)
    {
        age = a;
    }
};

class couple {
    const person &husband;
    const person &wife;
public:
    couple(const person &a,const person &b) : husband(a) , wife (b)
    {
        //a.setAge(1020);
    }
    
    const person& getHusband()
    {
        //husband.setAge(100);  //mutation is to avoided!
        return husband;
    }
    
    const person& getwife()
    {
        return wife;
    }
    
//    void setHusband(person &h)
    {
        husband = h;
    }
    
    void setwife(person &w)
    {
        wife = w;
    }
 
 
};

class testConst
{
    const int x;
    int y;
public:
    testConst() : x(0) , y(0)
    {
    }
    
    testConst(int init, int c=0) : x(init) , y(c)
    {
    
        
    }
};

int main()
{
    testConst a;
    testConst b(10,20);
    
    
    person h("ranveer", 28, 1) , w("daman" , 22 , 0);
    
    couple c(h,w);
    
    person &h1 = c.getHusband();
    //h1.setAge(32);
    
    cout << h1.getAge();
    cout << h.getAge();
    
    
    return 0;
}

*/

class A {
public:
    int data;

    virtual void show()
    {
        cout << "in a " << data << endl;
    }
};

class B : public A {
public:
    void show()
    {
        cout << "in b "<<data<<endl;
    }
};

class C:public A {
public:
    void show(){
        cout <<"in c " <<data<<endl;
    }
};

int main(){
    A* ptr;
    A a;
    B b;
    C c;
    a.data = 10;
    b.data = 20;
    c.data = 30;
    
    a.show();
    b.show();
    c.show();
    
    ptr = &a;
    ptr->show();
    ptr = &b;
    ptr->show();
    ptr = &c;
    ptr->show();
    
    
    return 0;
}






















