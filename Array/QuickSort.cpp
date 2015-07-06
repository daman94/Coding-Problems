//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void QuickSort (int *arr, int left, int right)
{
    if (left < right)
    {
        int pivot = arr[left];
        int i, low=left, high=left;
        
        for (i=left+1; i<=right; i++)
        {
            if (arr[i] < pivot)
            {
                low++;
                if (low!=i)
                {
                    swap(&arr[low], &arr[i]);
                }
                high++;
            }
            else
            {
                high++;
            }
        }
        
        swap(&arr[low], &arr[left]);
        
        QuickSort(arr, left, low-1);
        QuickSort(arr, low+1, right);
    }
    else
        return;
    
}

int main() {
    
    int arr[] = {5,4,3,2,1};
    
    
    int n = sizeof(arr) / sizeof(int);
    
    QuickSort(arr,0, n-1);
    
    
    for (int i=0; i<n; i++)
    {
        printf(" %d ", arr[i]);
    }
    
    return 0;
}