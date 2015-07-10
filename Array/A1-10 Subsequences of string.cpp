//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <list>
#include <string>
using namespace std;

list<string> myList;

void PrintList(list<string> l)
{
    list<string>::iterator it;
    
    for (it=l.begin(); it!=l.end(); it++)
    {
        cout << *it <<" ";
    }
}

void PrintSubsequences(char *str, int s, int t, char* temp, int n)
{
    if (s == n)
    {
        myList.push_back(temp);
        return;
    }
    
    temp[t] = str[s];
    temp[t+1] = '\0';
    PrintSubsequences(str, s+1, t+1, temp, n);
    temp[t] = '\0';
    PrintSubsequences(str, s+1, t, temp, n);
}


int main()
{
    char str[] = "abcd";
    int n= sizeof(str)/sizeof(str[0]);
    
    char temp[n+1];
    
    PrintSubsequences(str, 0, 0, temp, n-1);
    
    PrintList(myList);
    
    return 0;
}

