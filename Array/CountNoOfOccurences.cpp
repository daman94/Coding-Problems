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

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int first(int *arr, int left, int right, int x)
{
    if (left <= right)
    {
        int mid = (left+right)/2;
        if (arr[mid] == x && arr[mid-1] != x)
        {
            return mid;
        }
        
        else if (arr[mid] < x)
        {
            return first(arr, mid+1, right, x);
        }
        
        else
        {
            return first(arr, left, mid-1, x);
        }
    }
    
    return -1;
}

int last(int *arr, int left, int right, int x)
{
    if (left <= right)
    {
        int mid = (left+right)/2;
        if (arr[mid] == x && arr[mid+1] != x)
        {
            return mid;
        }
        
        else if (arr[mid] > x)
        {
            return last(arr, left, mid-1, x);
        }
        
        else
        {
            return last(arr, mid+1, right, x);
        }
    }
    
    return -1;
}

int count(int *arr, int n, int x)
{
    int i = first(arr, 0, n-1, x);
    int j = last(arr, 0, n-1, x);
    
    if (i==-1 || j==-1)
    {
        return -1;
    }
    
    else
    {
        return j-i+1;
    }
}

int main()
{
    int a[] = {1,1,2,2,2,2,3,3,4};
    int n = sizeof(a)/sizeof(int);
    
    cout << count(a,n,4);
    
    return 0;
}