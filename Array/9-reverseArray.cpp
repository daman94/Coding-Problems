//
//  main.c
//  Random C program
//
//  Created by Daman Saroa on 08/06/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MAX 10000

void reverseArray(int *arr, int start, int end);
void swap(int *a, int *b);

using namespace std;

int main()
{
    int a[] = {1,2,3,4,6};
    int n = sizeof(a)/sizeof(int);
    
    reverseArray(a, 0, n-1);
    
    for (int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}


//Functions

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverseArray(int *a, int start, int end)
{
    if (start > end)
    {
        return;
    }
    swap(&a[start] , &a[end]);
    reverseArray(a, start+1, end-1);
    
}



