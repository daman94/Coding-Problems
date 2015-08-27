//
//  main.cpp
//  Random C++ program
//
//  Created by Daman Saroa on 16/08/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include<iostream>
#define N 30000
using namespace std;

int B[N]={0};

int func(int a, int b, int m)
{
    B[0]= m;
    B[1] = a%m;
    if (B[b] != 0)
        return B[b];
    
    if(b%2 ==0)
    {
        return B[b] = (func(a, b/2, m) * func(a, b/2, m) )%m;
    }
    
    else
    {
        return B[b] = (func(a, b-1, m) * B[1]) %m;
    }
}


int main()
{
    cout << func(2199, 1925, 21223);
    return 0;
}