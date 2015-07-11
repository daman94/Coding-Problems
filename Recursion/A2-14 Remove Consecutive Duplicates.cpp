//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
using namespace std;

void removeUtil(char *current, char *prev)
{
    if (*current)
    {
        while (*current == *prev)
        {
            current++;
        }
        prev++;
        *prev = *current;
        removeUtil(current, prev);
    }
    
    else
    {
        return;
    }
}

void removeConsecutiveDuplicates(char *str)
{
    removeUtil(str,str);
}

int main()
{
    char str[] = "aabbbbvcvccba";
    
    removeConsecutiveDuplicates(str);
    
    cout << str;
    
    return 0;
}