//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void InsertionSort(int *arr, int n)
{
    int i,j,key;
    for (i=1 ; i<n; i++)
    {
        key = arr[i];
        j = i-1;
        while (j>=0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = key;
    }
}

int main() {
    
    int arr[] = {2,3,1,5,4};
    
    
    int n = sizeof(arr) / sizeof(int);
    
    InsertionSort(arr, n);
    
    
    for (int i=0; i<n; i++)
    {
        printf(" %d ", arr[i]);
    }
    
    return 0;
}