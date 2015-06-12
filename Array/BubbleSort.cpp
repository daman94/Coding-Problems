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

void bubbleSort(int arr[], int n)
{
    for (int j = n-2; j>=0 ; j--)
    {
        for (int i = 0; i<=j; i++)
        {
            if (arr[i] > arr[i+1])
            {
                swap(&arr[i], &arr[i+1]);
            }
        }
    }
}

int main() {
    
    int arr[] = {5,4,3,2,1};
    
    int n = sizeof(arr) / sizeof(int);
    
    bubbleSort(arr, n);
    
    for (int i=0; i<n; i++) {
        printf(" %d ", arr[i]);
    }
    
    return 0;
}