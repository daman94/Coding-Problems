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

void Permute(char *str, int l, int h)
{
    if (l == h)
    {
        cout <<str<<" ";
        return;
    }
    
    for (int i=l; i<=h; i++)
    {
        swap(&str[l], &str[i]);
        Permute(str, l+1, h);
        swap(&str[l], &str[i]);
    }
}


int main()
{
    char str[] = "abc";
    int n= sizeof(str)/sizeof(str[0]);
    
    Permute(str, 0, n-2);
    
    return 0;
}

