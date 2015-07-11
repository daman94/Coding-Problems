//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void Reverse(char *s, char *e)
{
    while (s<e)
    {
        swap(s, e);
        s++;
        e--;
    }
}

void ReverseWords(char *str)
{
    char *start = str;
    char *end = str;
    
    while (*end)
    {
        end++;
        if (*end == ' ')
        {
            Reverse(start, end-1);
            start = end+1;
        }
        else if (*end == '\0')
        {
            Reverse(start, end-1);
        }
    }
    Reverse(str, end-1);
    
}

int main()
{
    char a[] = "Daman Saroa";
    
    ReverseWords(a);
    
    cout << a ;
    
    return 0;
}