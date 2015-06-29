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


int main()
{
    int arr[] = {2,1,4,2,2,1,2,1,1,1,1,1};
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
        
        if (count == 0)
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
    
    if (count > n/2)
    {
        return 1;
    }
    else
        return 0;
}

void printMajority(int *arr, int n)
{
    int x = findCandidate(arr, n);
    
    if (isMajority(arr, n, x)) {
        cout << "The majority element is : "<< x;
    }
}
















