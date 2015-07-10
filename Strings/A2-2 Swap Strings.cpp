//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
using namespace std;

void swap(char *a, char *b)
{
    //swaps a character
    char temp = *a;
    *a = *b;
    *b = temp;
}

void swapStrings(char **a, char **b)
{
    char *temp =*a;
    *a=*b;
    *b=temp;
    
}

int main()
{
    char *a = "Saroa";
    char *b = "Daman";
    
    
    
    swapStrings(&a, &b);
    
    cout << a << endl;
    
    cout << b << endl;
    
    
    return 0;
}