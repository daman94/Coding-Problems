//
//  main.cpp
//  Random C++ program
//
//  Created by Daman Saroa on 16/08/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
using namespace std;

void printMatrix(int arr[8][8])
{
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(int arr[8][8], int i, int j)
{
    int m,n;
    
    //row and col
    for (m=0; m<8; m++) {
        if (arr[i][m] != -1 || arr[m][j] != -1) {
            return false;
        }
    }
    
    //upper diagonal
    m=i, n=j;
    while (m!=0) {
        if (arr[m--][n--]!= -1) {
            return false;
        }
    }
    
    //lower diagonal
    m=i, n=j;
    while (n!=7) {
        if (arr[m++][n++]!= -1) {
            return false;
        }
    }
    
    return true;
}

void placeQueen(int arr[8][8], int i, int j)
{
    if (i==7 && j==7) {
        printMatrix(arr);
        return;
    }
    else if(j>7)
    {
        
    }
    else
    {
        if( isSafe(arr, i,j) )
        {
            arr[i][j] = 0;
            placeQueen(arr, i+1, 0);
        }
        else
            placeQueen(arr, i, j+1);
    }
}


int main()
{
    int arr[8][8];
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            arr[i][j] = -1;
        }
    }
    
    placeQueen(arr, 0, 0);
    
    
    
    return 0;
}


































