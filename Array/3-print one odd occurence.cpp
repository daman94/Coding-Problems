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

//Given an array of positive integers. All numbers occur even number of times except one number which occurs odd number of times. Find the number in O(n) time & constant space.

void getOddOccurences(int *arr, int n);
int main()
{
    int arr[] = {1,1,2,3,1,2,3,2};
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
    
    if (res == 0) {
        cout << "All even occurences";
    }
    else
    {
        cout << res;
    }
}

























