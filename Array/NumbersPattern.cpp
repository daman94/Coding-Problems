//
//  NumbersPattern.cpp
//  Random C++ program
//
//  Created by Daman Saroa on 19/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <stdio.h>
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

int main()
{
    int i = 1;
    int j;
    
    for (i = 1; i<=5; i++)
    {
        int k = 5-i;
        while (k >0)
        {
            printf(" ");
            k--;
        }
        
        for (j=i ; j <= i*2 - 1; j++)
        {
            printf("%d", j);
        }
        
        j--;
        
        while (j!=i)
        {
            j--;
            printf("%d",j);
        }
        
        printf("\n");
    }
    
    
    
    
    return 0;
}








