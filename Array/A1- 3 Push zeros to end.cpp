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
    *b =temp;
}

void pushZerosToEnd(int *arr, int size)
{
    int i,count=0;
    
    for (i=0; i<size ; i++)
    {
        if (arr[i] != 0)
        {
            arr[count] = arr[i];
            count++;
        }
    }
    
    while (count<size)
    {
        arr[count] = 0;
        count++;
    }
}

int main()
{
    int arr[] = {1,2,0,0,2,3,5,0,0,4,0,5,0,8,0,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    pushZerosToEnd(arr, size);
    
    for (int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}