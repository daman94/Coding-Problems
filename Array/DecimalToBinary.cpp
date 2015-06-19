//
//  main.c
//  Random C program
//
//  Created by Daman Saroa on 08/06/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//

#include <iostream>
#define MAX 100000
using namespace std;

void binIterative(unsigned n)
{
    unsigned i;
    
    for (i = 1 << 4; i > 0; i = i / 2)
        (n & i)? printf("1"): printf("0");
}

void binRecurssive(unsigned n)
{
    if (n>1)
    {
        binRecurssive(n/2);
    }
    
    cout << n%2;
    
}

int main(void)
{
    binIterative(10);
    printf("\n");
    binRecurssive(10);
    
    return 0;
}

