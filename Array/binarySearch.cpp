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


int binarySearch(int *arr, int l, int r, int key);

int main(void)
{
    int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr)/sizeof(int);
    
    
    int loc = binarySearch(arr, 0, size-1, 6);
    
    cout << loc;
    
    return 0;
}


//Functions

int binarySearch(int *arr, int l, int r, int key)
{
    if ( l <= r)
    {
        int mid = (l+r)/2;
        
        if (arr[mid] == key)
        {
            return mid;
        }
        
        else if(arr[mid] < key)
        {
            return binarySearch(arr, mid+1, r, key);
        }
        else
        {
            return binarySearch(arr, l, mid-1, key);
        }
    }
    
    return -1;
    
}
