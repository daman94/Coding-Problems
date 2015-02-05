//
//  main.cpp
//  Sorting library
//
//  Created by Daman Saroa on 06/01/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include "Sort.h"
using namespace std;

class Person {
    int grade;
    int marks;
    
public:
    
    int getMarks()
    {
        return marks;
    }
    
    Person(int c=0 , int m=0)
    {
        grade = c;
        marks = m;
    }
    
};

class Dog {
    int age;
public:
    int getAge()
    {
        return age;
    }
    
    Dog(int a=0)
    {
        age = a;
    }
};

class comparePersons {
    bool asc;
public:
    comparePersons(bool flag = true) {
        asc = flag;
    }
    
    bool compare(Person& p1, Person& p2)
    {
        if (asc)
        {
            return p1.getMarks() < p2.getMarks();
        }
        else
        {
            return p1.getMarks() > p2.getMarks();
        }
    }
};

class compareDogs {
public:
    bool compare(Dog& d1, Dog& d2)
    {
        return d1.getAge() < d2.getAge();
    }
};

int main()
{
    Person prateek(10 , 17);
    Person daman (10, 13);
    Person khushdil(12, 19);
    
    Person parr[3];
    parr[0] = prateek;
    parr[1] = daman;
    parr[2] = khushdil;
    
    for (int i=0; i<3; i++)
    {
        cout << parr[i].getMarks() << " ";
    }
    cout << endl;
    
    Sort<Person , comparePersons> S;
    Person p;
    comparePersons cp(true);
    
    S.bubbleSort(parr , 0 ,3 , cp);
    
    for (int i=0; i<3; i++) {
        cout << parr[i].getMarks() << " ";
    }
    
    cout << endl << endl;
    
    
    Dog browny(3);
    Dog tom(2);
    Dog raww(6);
    
    Dog darr[3];
    darr[0] = browny;
    darr[1] = tom;
    darr[2] = raww;
    
    Sort<Dog , compareDogs> D;
    
    
    return 0;
}