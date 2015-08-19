//
//  main.cpp
//  Random C++ program
//
//  Created by Daman Saroa on 16/08/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#define N 100
using namespace std;

int f[N]={0};


//by dp
int fib(int n)
{
    f[1]=1;
    f[2]=1;
    
    if (f[n]!=0) return f[n];
    
    return f[n] = fib(n-1)+fib(n-2);
}


void fibo(int n)
{
    int a=0;
    int b=1;
    int sum;
    cout<<a<<" "<<b<<" ";
    for (int i=2 ; i<n; i++) {
        sum=a+b;
        cout<<sum<<" ";
        a=b;
        b=sum;
    }
}

int main()
{
    int n=15;
    
    cout << fib(n)<<endl;
    
    for (int i=0; i<n; i++)
    {
        cout<<f[i]<<" ";
    }
    
    
    return 0;
}