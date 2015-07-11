//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#define M 3
#define N 3
using namespace std;


//BUGGGYYY
void printSpiral(int arr[][N], int x, int m, int n )
{
    if ( x==2 )
    {
        return;
    }
    
    int i,j;
    
    //first row
    i=x;
    for (j=x; j<n-x-1; j++)
    {
        cout << arr[i][j] << " ";
    }
    
    //last col
    j=n-x-1;
    for (i=x; i<m-x-1; i++)
    {
        cout << arr[i][j] << " ";
    }
    
    //last row
    i=m-x-1;
    for (j=n-x-1; j>x; j--)
    {
        cout << arr[i][j] << " ";
    }
    
    //first col
    j=x;
    for (i=m-x-1; i>x; i--)
    {
        cout << arr[i][j] << " ";
    }
    
    printSpiral(arr, x+1, m,n);
    
}

int main()
{
    int a[M][N] = { {1,2,3},
        {5,6,7},
        {9,10,11}
    };
    
    
    
    printSpiral(a, 0, M, N);
    
    return 0;
}