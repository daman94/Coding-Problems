//
//  main.c
//  Random C program
//
//  Created by Daman Saroa on 08/06/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MAX 10000

using namespace std;

//Two numbers occuring odd times

void getOddOccurences(int *arr, int n);
int main()
{
    int arr[] = {1,3,2,3,1,2,3,2};
    int n = sizeof(arr)/sizeof(int);
    
    getOddOccurences(arr, n);
    
    return 0;
}

void getOddOccurences(int *arr, int n)
{
    int res = 0;
    for (int i=0; i<n; i++)
    {
        res = res ^ arr[i];
    }
    
    //res contains xor of x and y..two numbers occuring odd times
    
    int firstBit = res & ~(res-1);
    int x=0,y=0;
    
    for (int i=0; i<n; i++)
    {
        if (arr[i] & firstBit)
        {
            x = x ^ arr[i];
        }
        else
        {
            y = y ^ arr[i];
        }
    }
    
    cout << "Two odd occuring values are: "<< x << " and "<< y;
    return;
}

























