//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
using namespace std;

void Subset(int *arr, int *temp, int a, int t, int sum, int size)
{
    if (a == size)
    {
        return;
    }
    
    if (sum-arr[a] == 0)
    {
        temp[t] = arr[a];
        for (int i=0; i<=t; i++)
        {
            cout << temp[i] << " ";
        }
        cout<<endl;
    }
    
    if (sum-arr[a] > 0)
    {
        temp[t] = arr[a];
        Subset(arr, temp, a+1, t+1, sum-arr[a], size);
    }
    
    Subset(arr, temp, a+1, t, sum, size);
    
}

int main()
{
    int arr[] = {5,2,1,1,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int temp[n];
    
    Subset(arr, temp, 0, 0, 5, n);
    
    
    return 0;
}