//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>

using namespace std;

int getMax(int *arr, int n)
{
    int max = arr[0];
    
    for (int i=1; i<n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

void CountSort(int *arr, int n, int exp)
{
    int i, count[10]={0}, output[n];
    int b[n];
    
    for (i=0; i<n; i++)
    {
        b[i] = (arr[i]/exp) %10;
    }
    
    for (i=0; i<n; i++)
    {
        count[b[i]]++;
    }
    
    for (i=1; i<10; i++)
    {
        count[i] = count[i-1] + count[i];
    }
    
    for (i=n-1; i>0; i--)
    {
        output[count[b[i]] - 1] = arr[i];
        count[ b[i] ] -- ;
    }
    
    for (i=0; i<n; i++) {
        arr[i] = output[i];
    }
}

void RadixSort(int *arr, int n)
{
    int max = getMax(arr, n);
    
    for (int exp=1; max/exp >0; exp = exp*10)
    {
        CountSort(arr, n, exp);
    }
}


int main() {
    
    int arr[] = {170,45,75,90,802,24,2,66};
    int n = sizeof(arr) / sizeof(int);
    
    RadixSort(arr, n);
    
    for (int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}
























