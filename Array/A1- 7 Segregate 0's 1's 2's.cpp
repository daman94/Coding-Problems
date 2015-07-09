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

void segregate0s1s2s(int *arr, int n)
{
    int l=0;
    int m=0;
    int h=n-1;
    
    
    while (m<=h)
    {
        if (arr[m] == 0)
        {
            swap(&arr[m], &arr[l]);
            m++;
            l++;
        }
        
        else if (arr[m] == 1)
        {
            m++;
        }
        
        else if (arr[m] == 2)
        {
            swap(&arr[m], &arr[h]);
            h--;
        }
        
    }
}


int main()
{
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n= sizeof(arr)/sizeof(arr[0]);
    
    segregate0s1s2s(arr, n);
    
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}

