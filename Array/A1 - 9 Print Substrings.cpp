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

void PrintSubstring(char *str, int l, int h)
{
    if (l<=h)
    {
        cout << str[l];
        PrintSubstring(str, l+1, h);
    }
    
    else
        cout<<" ";
    
}

void PrintAllSubstrings(char* str, int n)
{
    for (int i=0; i<n-1; i++)
    {
        for (int j=i; j<n-1; j++)
        {
            PrintSubstring(str, i, j);
        }
    }
}



int main()
{
    char str[] = "abcde";
    int n= sizeof(str)/sizeof(str[0]);
    
    PrintAllSubstrings(str, n);
    
    
    //cout<<str;
    
    return 0;
}

