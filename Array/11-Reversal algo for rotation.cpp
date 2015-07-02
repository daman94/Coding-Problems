//
//  main.c
//  Random C program
//
//  Created by Daman Saroa on 08/06/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

void swap(int *a, int *b);
void rotate(int *arr, int n, int d);
void reverse(int *arr, int start, int end);

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int n= sizeof(arr)/sizeof(arr[0]);
    
    int d = 3;
    
    rotate(arr,n,d);
    
    for (int i=0; i<n; i++)
    {
        cout << arr[i]<<" ";
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

void reverse(int *arr, int start, int end)
{
    while (start < end)
    {
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}

void rotate(int *arr, int n, int d)
{
    reverse(arr, 0, d-1);
    reverse(arr, d, n-1);
    reverse(arr,0,n-1);
}























