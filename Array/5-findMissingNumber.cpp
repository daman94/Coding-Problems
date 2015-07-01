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

void findMissingNumber(int *arr, int n);
void findMissingNumberXorMethod(int *arr, int n);

int main()
{
    int arr[] = {2,1,4,3,6,7,8};
    int n = sizeof(arr)/sizeof(int);
    
    
    findMissingNumberXorMethod(arr, n);
    
    return 0;
}


//Functions

void findMissingNumber(int *arr, int n)
{
    int sum = ((n+1)*(n+2)) / 2 ;
    
    for(int i=0;i<n;i++)
    {
        sum = sum - arr[i];
    }
    
    cout << sum;
}

void findMissingNumberXorMethod(int *arr, int n)
{
    int xor1 = arr[0];
    int xor2 = 1;
    int i;
    
    for (i=1; i<n; i++)
    {
        xor1 = xor1 ^ arr[i];
    }
    
    for (i=2; i<=n+1; i++) {
        xor2 = xor2 ^ i;
    }
    
    cout << (xor1 ^ xor2);
}
















