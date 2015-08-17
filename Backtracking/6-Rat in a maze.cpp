//
//  main.cpp
//  Random C++ program
//
//  Created by Daman Saroa on 16/08/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#define N 4
using namespace std;

bool isSafe(int arr[4][4], int row, int col)
{
    return arr[row][col] == 1;
}


bool solve(int arr[4][4], int row, int col)
{
    //destination
    if (row==N-1 && col == N-1)
    {
        arr[row][col] = 2;
        return true;
    }
    
    if (isSafe(arr, row, col))
    {
        arr[row][col] = 2;
        bool ok = solve(arr,row+1,col);
        bool ok2 = solve(arr, row, col+1);
        
        if (ok || ok2) return  true;
        else
            arr[row][col] = 0;
        
    }
    
    
    return false;
}

int main()
{
    int maze[N][N]  =  { {1, 1, 1, 0},
        {1, 0, 1, 1},
        {0, 1, 1, 0},
        {1, 1, 1, 1}
    };
    
    if (solve(maze, 0, 0)) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                cout << maze[i][j] << " ";
            }
            cout<<endl;
        }
    }
    
    return 0;
}




