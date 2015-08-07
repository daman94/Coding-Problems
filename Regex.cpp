//
//  main.c
//  Random C program
//
//  Created by Daman Saroa on 08/06/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//
#include<iostream>
using namespace std;

bool func(string s, string ex, int i, int j)
{
    if (j == s.length() && i == ex.length()) {
        return true;
    }
    
    if (ex[i] >= 'a' && ex[i] <= 'z') {
        if (s[j] == ex[i]) {
            return func(s, ex, i+1, j+1);
        }
    }
    
    if (ex[i] == '.') {
        return func(s, ex, i+1, j+1);
    }
    
    if (ex[i] == '*') {
        if (s[j] == ex[i-1]) {
            return func(s, ex, i, j+1) || func(s, ex, i+1, j);
        }
        else
            return func(s,ex , i+1, j);
    }
    
    return false;
}

int main()
{
    string s = "aabbc";
    string ex = "a*.b*c";
    
    if(func(s, ex, 0, 0))
        cout << "accepted";
    else
        cout << "not accepted";
    
    return 0;
}