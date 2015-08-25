//
//  main.cpp
//  Random C++ program
//
//  Created by Daman Saroa on 16/08/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#define n 8;
using namespace std;

bool isSafe(int arr[8][8], int row, int col)
{
    //row clear?
    
    for (int i=0; i<8; i++)
    {
        if (arr[row][i] == 1) return false;
    }
    
    //lower diagonal
    
    int i=row, j=col;
    
    while (i<8 && j<8) {
        if (arr[i][j] == 1) return false;
        i++;
        j++;
    }
    
    //upper diagonal
    i=row, j=col;
    
    while (i>0 && j>0) {
        if (arr[i][j] == 1) return false;
        i--;
        j--;
    }
    return true;
}

bool solve(int arr[8][8], int col)
{
    if (col>=8) return true;
    
    for (int rowToTry = 0; rowToTry <= 8; rowToTry++) {
        if (isSafe(arr, rowToTry, col)) {
            arr[rowToTry][col] = 1;
            bool ok = solve(arr, col+1);
            if (ok) return true;
            else arr[rowToTry][col] = 0;
        }
    }
    
    return false;
}


int main()
{
    
    int arr[8][8] = {0};
    
    if (solve(arr, 0))
    {
        for (int i=0; i<8; i++) {
            for (int j=0; j<8; j++) {
                cout << arr[i][j] << " ";
            }
            
            cout << endl;
        }
    }
    
    return 0;
}






