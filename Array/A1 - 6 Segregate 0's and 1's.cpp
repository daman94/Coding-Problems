//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void segregate0s1s(int *arr, int n)
{
    int i=0, j=n-1;
    
    while (i<=j)
    {
        while (arr[i]==0)
        {
            i++;
        }
        
        while (arr[j]==1)
        {
            j--;
        }
        
        //now i and j points to 1 and 0 resp
        
        if (i<j)
        {
            swap(&arr[i], &arr[j]);
            
        }
        
    }
    
    
}


int main()
{
    int arr[] = {0,1,0,1,0,0,1,1,1,0};
    int n= sizeof(arr)/sizeof(arr[0]);
    
    segregate0s1s(arr, n);
    
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}

