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

int binarySearch(int *arr, int left, int right, int size , int key);
int findRotationFactor(int *arr, int left, int right);
int pivottedBinarySearch(int *arr, int size, int key);

//***********  MAIN  ****************//
int main(void)
{
    int arr[] = {3,4,5,1,2};
    int size = sizeof(arr)/sizeof(int);
    
    int key = 4 ;
    
    int loc = pivottedBinarySearch(arr, size, key);
    
    cout << findRotationFactor(arr, 0, size-1);
    
    
    return 0;
}


//Functions

int binarySearch(int *arr, int left, int right, int size , int key)
{
    if(right<left)
    {
        return -1;
    }
    
    if (left == right) {
        return left;
    }
    
    int mid = (left+right)/2;
    
    if (arr[mid] == key)
    {
        return mid;
    }
    
    else if(arr[mid] < key)
    {
        return binarySearch(arr, mid, right, size, key);
    }
    else
    {
        return binarySearch(arr, left, mid, size, key);
    }
    
}

int pivottedBinarySearch(int *arr, int size, int key)
{
    int pivot = findRotationFactor(arr, 0, size-1);
    
    if (pivot == -1)
    {
        return binarySearch(arr, 0, size-1, size, key);
    }
    
    else
    {
        if (arr[pivot] == key)
        {
            return pivot;
        }
        
        else if (arr[0] <= key)
        {
            return binarySearch(arr, 0, pivot-1, size, key);
        }
        
        else
        {
            return binarySearch(arr, pivot+1, size-1, size, key);
        }
        
    }
    
    
}

int findRotationFactor(int *arr, int left, int right)
{
    if (left > right)
    {
        return -1;
    }
    
    if (left == right)
    {
        return left;
    }
    
    int mid = (left+right)/2;
    
    if (mid < right  &&  arr[mid] > arr[mid+1])
    {
        return mid;
    }
    
    else if (mid > left && arr[mid] < arr[mid-1])
    {
        return (mid-1);
    }
    
    else if (arr[left] >= arr[mid])
    {
        return findRotationFactor(arr, left, mid-1);
    }
    
    else
    {
        return findRotationFactor(arr, mid+1, right);
    }
    
}