//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
using namespace std;

int countDigits(int num, int count)
{
    if (num/10 > 0)
    {
        count++;
    }
    
    else
    {
        return count;
    }
    
    return countDigits(num/10, count);
}

int main()
{
    int num = 379696800;
    
    cout << countDigits(num, 1);
    
    return 0;
}