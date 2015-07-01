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

void maxSubArray(int *arr, int n);


int main()
{
    int arr[] = {-2,-3,4,-1,-2,1,5,-3};
    int n = sizeof(arr)/sizeof(int);
    
    maxSubArray(arr, n);
    return 0;
}


//Functions

void maxSubArray(int *arr, int n) {
    int maxSumArray[n];
    
    maxSumArray[0] = arr[0];
    
    int i = 1;
    
    while (i < n)
    {
        if (maxSumArray[i-1] + arr[i]  >= arr[i] ) {
            maxSumArray[i] = maxSumArray[i-1] + arr[i];
        }
        
        else
        {
            maxSumArray[i] = arr[i];
        }
        
        i++;
    }
    
    i=0;
    int max = 0;
    while (i<n)
    {
        if (max < maxSumArray[i])
        {
            max = maxSumArray[i];
        }
        i++;
    }
    
    cout << "The maximum sum is: "<< max;
    
}
