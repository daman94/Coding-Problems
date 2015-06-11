//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//
//Merge Sort

#include <iostream>

void merge(int a[], int l,int m, int r)
{
    int n1 = m-l+1;
    int n2 = r-m;
    
    int left[n1];
    int right[n2];
    
    for (int i=0; i<n1; i++) {
        left[i] = a[l+i];
    }
    
    for (int i=0; i<n2; i++) {
        right[i] = a[m+1+i];
    }
    
    int j=0, k=0, i=l;
    
    while ( j < n1 && k < n2)
    {
        if (left[j] <= right[k])
        {
            a[i] = left[j];
            j++;
            i++;
        }
        else {
            a[i] = right[k];
            k++;
            i++;
        }

    }
    
    while (j<n1)
    {
        a[i] = left[j];
        i++;
        j++;
    }
    
    while (k<n2)
    {
        a[i] = right[k];
        i++;
        k++;
    }
    
    
    
    
}

void mergeSort( int a[], int l, int r)
{
    if (l<r)
    {
        int mid = (l+r)/2;
        mergeSort(a, l, mid);
        mergeSort(a, mid+1, r);
        merge(a, l, mid, r);
    }
}


int main() {
    
    int a[] = {5,2,4,1,3};
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
