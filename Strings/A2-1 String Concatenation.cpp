//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
using namespace std;

void strcat(char *a, char *b)
{
    char* i = a;
    
    while (*i != '\0')
    {
        i++;
    }
    
    char* j = b;
    
    while (*j != '\0')
    {
        *i = *j;
        i++;
        j++;
    }
    
    *j = '\0';
    return;
}

int main()
{
    char str[] = "abc";
    char str2[] = "def";
    int n = sizeof(str)/sizeof(str[0]);
    
    strcat(str, str2);
    
    cout << str;
    
    
    return 0;
}