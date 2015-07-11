//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#define MAX 20
using namespace std;

void func(char arr[][MAX], int x, int n, char ch)
{
    if (x==n)
    {
        return;
    }
    
    int i,j;
    
    i=x;
    for (j=x; j<n-x; j++)
    {
        arr[i][j] = ch;
    }
    
    i=n-x-1;
    for (j=x; j<=i; j++)
    {
        arr[i][j] = ch;
    }
    
    j=x;
    for (i=x; i<n-x; i++)
    {
        arr[i][j] = ch;
    }
    
    j=n-x-1;
    for (i=x; i<=j; i++)
    {
        arr[i][j] = ch;
    }
    
    if (x%2 == 0)
        ch = 'x';
    else
        ch = 'o';
    
    func(arr, x+1, n,ch);
}

int main()
{
    char arr[MAX][MAX] = {'x'};
    
    int n = 5;
    
    func(arr, 0, n, 'o');
    
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            cout << arr[i][j] << " ";
        }
        
        cout << endl;
    }
    
    return 0;
}