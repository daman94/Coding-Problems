//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//
//Merge Sort

#include <iostream>

void merge(int *arr, int l,int m, int r)
{
    int n1 = m-l+1;
    int n2 = r-m;
    
    int left[n1], right[n2];
    
    for (int i=0; i<n1; i++)
    {
        left[i] = arr[l+i];
    }
    
    for (int i=0; i<n2; i++)
    {
        right[i] = arr[m+1+i];
    }
    
    int i=0, j=0, k=l;
    
    while (i<n1 && j<n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
            k++;
        }
    }
    
    while (i<n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    
    while (j<n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}


void mergeSort(int *arr, int left, int right)
{
    if (left < right)
    {
        int mid = (left+right)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr, mid+1, right);
        merge(arr,left,mid,right);
    }
}


int main() {
    
    int a[] = {5,2,4,1,3,1,6};
    int n = sizeof(a)/sizeof(int) ;
    
    
    for (int i=0; i<n; i++)
    {
        printf(" %d ",  a[i]);
    }
    
    mergeSort(a, 0, n-1);
    
    printf("After sorting...");
    
    for (int i=0; i<n; i++)
    {
        printf(" %d ",  a[i]);
    }
    
    
    
    return 0;
}
