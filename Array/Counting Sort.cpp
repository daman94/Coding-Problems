//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>

void CountingSort(int *A, int *B, int n, int k)
{
    int C[k];
    int i;
    
    for (i=0; i<k; i++)
    {
        C[i] = 0;
    }
    
    for (i=0; i<n; i++)
    {
        C[A[i]] = C[A[i]] + 1;
    }
    
    for (i=1; i<k; i++)
    {
        C[i] = C[i-1] + C[i];
    }
    
    for (i=0; i<n; i++)
    {
        B[ C[A[i]] - 1] = A[i];
        C[A[i]] = C[A[i]] - 1;
    }
}

int main() {
    
    int arr[] = {5,4,3,2,2,3,1,4,1};
    int n = sizeof(arr) / sizeof(int);
    int B[n];
    
    CountingSort(arr, B, n, 10);
    
    
    for (int i=0; i<n; i++)
    {
        printf(" %d ", B[i]);
    }
    
    return 0;
}