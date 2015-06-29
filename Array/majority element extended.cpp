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

int findCandidate(int *arr, int n);
bool isMajority(int *arr, int n, int x);
void printMajority(int *arr, int n);

//Given an array of 2n elements of which n elements are same and the remaining n elements are all different. Write a C program to find out the value which is present n times in the array.

int main()
{
    int arr[] = {1,1,1,2,3,4,1,1};
    int n = sizeof(arr)/sizeof(int);
    
    printMajority(arr, n);
    
    
    return 0;
}

//Functions
int findCandidate(int *arr, int n)
{
    int maj_index = 0, count=1;
    
    for (int i=0; i<n; i++)
    {
        if (arr[maj_index] == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        
        if (count < 0)
        {
            maj_index = i;
            count =1;
        }
    }
    
    return arr[maj_index];
}


bool isMajority(int *arr, int n, int x)
{
    int count=0;
    for (int i=0; i<n; i++)
    {
        if (arr[i] == x)
        {
            count++;
        }
    }
    
    if (count == n/2)
    {
        return 1;
    }
    else
        return 0;
}

void printMajority(int *arr, int n)
{
    if (n%2 != 0) {
        cout << "Array does not contain 2n elements";
        return;
    }
    int x = findCandidate(arr, n);
    
    if (isMajority(arr, n, x)) {
        cout << "The majority element is : "<< x;
    }
    else
    {
        cout << "No majority element found";
    }
}
















