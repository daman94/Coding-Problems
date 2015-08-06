//
//  main.c
//  Random C program
//
//  Created by Daman Saroa on 08/06/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//
#include <iostream>
using namespace std;

void func(int* arr, int* output, int sum, int i, int o, int n)
{
    if(i==n)
        return;
    
    if (sum==0)
    {
        for (int i=0;i<o; i++) {
            cout<<output[i] <<" ";
        }
        
        cout<<endl;
        return;
    }
    
    output[o] = arr[i];
    func(arr, output, sum-arr[i], i+1, o+1,n);
    output[o]=0;
    func(arr, output, sum, i+1, o,n);
}



int main()
{
    int arr[] = {1,4,2,6,3,9};
    int temp[10];
    int n = sizeof(arr)/sizeof(arr[0]);
    func(arr,temp, 7, 0,0,n);
    
    return 0;
}