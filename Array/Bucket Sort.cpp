//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#define BUCKETS 10

using namespace std;


void BucketSort(int *arr, int n)
{
    int i,j,k;
    int bucket[BUCKETS];
    
    for (i=0; i<BUCKETS; i++)
    {
        bucket[i]=0;
    }
    
    for (i=0; i<n; i++)
    {
        ++bucket[arr[i]];
    }
    
    for (i=0,j=0; j<BUCKETS; j++)
    {
        for(k = bucket[j]; k>0; k--)
        {
            arr[i] = j;
            i++;
        }
    }
}

int main() {
    
    int arr[] = {5,4,3,2,2,3,1,4,1};
    int n = sizeof(arr) / sizeof(int);
    
    BucketSort(arr, n);
    
    for (int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}
























