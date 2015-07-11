//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
using namespace std;

int compute(int i, int j)
{
    if (i<0 || j<0)
    {
        return 0;
    }
    
    else if (i==0 && j==0)
    {
        return 1;
    }
    
    else
        return compute(i, j-1) + compute(i-1, j);
}

int main()
{
    int m = 3, n= 4;
    
    cout << compute(m-1, n-1);
    
    
    return 0;
}