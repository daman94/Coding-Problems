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

int f[N] = {0};

int fact(int n)
{
    f[1]=1;
    
    if (f[n]!=0)
    {
        cout<<n<<" this called      ";
        return f[n];
    }
    
    return f[n] = n*fact(n-1);
}

int main()
{
    cout << fact(7)<<endl;
    cout<< fact(6)<<endl;
    return 0;
}