//
//  main.cpp
//  Random C++ program
//
//  Created by Daman Saroa on 16/08/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
using namespace std;



bool NoConflicts(int sudoku[9][9], int row, int col, int num)
{
    //check row
    for (int i=0; i<9; i++) {
        if(sudoku[row][i] == num) return false;
    }
    
    //check col
    for(int i=0;i<9;i++)
        if(sudoku[i][col] == num) return false;
    
    //check subgrid
    row = row/3*3;
    col = col/3*3;
    
    for (int i=row; i<row+3; i++) {
        for (int j=col; j<col+3; j++) {
            if(sudoku[i][j] == num) return false;
        }
    }
    
    return  true;
}

bool findUnassignedLocation(int sudoku[9][9], int &row, int &col)
{
    for(row=0;row<9;row++)
    {
        for (col=0; col<9; col++) {
            if (sudoku[row][col] == 0) {
                return true;
            }
        }
    }
    return false;
}

bool solve(int sudoku[9][9])
{
    int row, col;
    
    if(!findUnassignedLocation(sudoku, row, col)) return true;
    
    for (int num=1; num<=9; num++)
    {
        if (NoConflicts(sudoku, row, col, num))
        {
            sudoku[row][col] = num;
            bool ok = solve(sudoku);
            if (ok) return true;
            else sudoku[row][col] = 0;
        }
    }
    
    return false;
}



int main()
{
    int mat[9][9] = {
        {8,0,0,7,5,0,0,4,0},
        {0,0,0,1,0,0,0,0,0},
        {5,1,0,4,0,6,0,0,7},
        {0,0,4,0,0,0,0,5,0},
        {1,0,5,0,0,0,7,0,8},
        {0,2,0,0,0,0,4,0,0},
        {0,0,0,9,0,2,0,6,1},
        {0,0,0,0,0,3,0,0,0},
        {0,0,0,0,6,1,0,0,5}};
    
    
    if (solve(mat))
    {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                cout << mat[i][j] << " ";
            }
            
            cout << endl;
        }
    }
    
    return 0;
}






