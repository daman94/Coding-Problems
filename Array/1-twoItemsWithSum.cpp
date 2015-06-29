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

void swap(int*,int*);
void sort(int *arr, int n, int i);
void twoItemsWithSum(int *arr, int n, int sum);
void twoItemsWithSumHashmap(int *arr, int n, int sum);

int main()
{
    int arr[] = {2,1,3,5,4};
    int n = sizeof(arr)/sizeof(int);
    
    //twoItemsWithSum(arr, n, 3);
    
    twoItemsWithSumHashmap(arr, n, 6);
    
    return 0;
}

//Functions

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *arr, int i, int n) {
    for (int i=n; i>0; i--) {
        for (int j=0; j<i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void twoItemsWithSum(int *arr, int n, int sum)
{
    sort(arr,arr+5);
    
    
    int i=0, j=n-1;
    
    while (i<j)
    {
        if (arr[i]+arr[j] == sum)
        {
            cout << arr[i] << " and " << arr[j] << " has sum " << sum;
            return;
        }
        else if (arr[i] + arr[j] < sum)
        {
            i++;
        }
        else
            j--;
    }
    
    cout << "No two items with sum " << sum << " found";
    return;
}

void twoItemsWithSumHashmap(int *arr, int n, int sum)
{
    bool binMap[MAX] = {0};
    
    for (int i=0; i<n; i++)
    {
        if (binMap[sum - arr[i]] == 1)
        {
            cout << "Items: " << arr[i] << " and " << sum - arr[i] << " has sum = " << sum;
        }
        
        binMap[arr[i]] = 1;
    }
    
}























