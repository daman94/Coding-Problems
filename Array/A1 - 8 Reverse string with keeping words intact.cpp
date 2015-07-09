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
    char temp = *a;
    *a = *b;
    *b = temp;
}

void reverseStringUtil(char *str, int l, int r)
{
    while (l<r)
    {
        swap(&str[l], &str[r]);
        l++;
        r--;
    }
}

void reverseString(char *str, int n)
{
    reverseStringUtil(str, 0, n-2);
    str[n-1] = '\0';
    
    int l=0;
    
    for (int i=0; i<n ; i++)
    {
        if (str[i] ==  ' ' || str[i] == '\0')
        {
            reverseStringUtil(str, l, i-1);
            l=i+1;
        }
        
    }
    
    
}

int main()
{
    char str[] = "welcome to CODING BLOCKS";
    int n= sizeof(str)/sizeof(str[0]);
    
    reverseString(str, n);
    
    cout<<str;
    
    return 0;
}

