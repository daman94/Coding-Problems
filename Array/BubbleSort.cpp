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
    int pass, swapped = 1;
    int i;
    for (pass=n-1; pass>=0 && swapped ; pass--)
    {
        swapped = 0;
        for (i=0; i<pass ; i++)
        {
            if (arr[i] > arr[i+1])
            {
                swapped = 1;
                swap(&arr[i], &arr[i+1]);
            }
        }
    }
}

int main() {
    
    int arr[] = {5,4,3,2,1};
    
    
    int n = sizeof(arr) / sizeof(int);
    
    bubbleSort(arr, n);
    
    for (int i=0; i<n; i++)
    {
        printf(" %d ", arr[i]);
    }
    
    //Bubble SOrt
    return 0;
}