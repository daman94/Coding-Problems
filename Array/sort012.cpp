//
//  main.c
//  Random C program
//
//  Created by Daman Saroa on 08/06/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort012(int *a, int n)
{
    int low = 0, mid = 0, high = n-1;
    
    while (mid <= high)
    {
        if (a[mid] == 0)
        {
            swap(&a[mid], &a[low]);
            mid++;
            low++;
        }
        
        else if (a[mid] == 1)
        {
            mid++;
        }
        
        else if (a[mid] == 2)
        {
            swap(&a[mid], &a[high]);
            high--;
        }
    }
}

int main()
{
    int a[] = {2,0,1,2,1};
    int n = sizeof(a)/sizeof(int);
    
    sort012(a,n);
    
    for (int i=0; i<n; i++)
    {
        cout << a[i];
    }
    
    
    return 0;
}