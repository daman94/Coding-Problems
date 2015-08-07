//
//  main.c
//  Random C program
//
//  Created by Daman Saroa on 08/06/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//
#include <iostream>
#include <cmath>
using namespace std;

bool isSafe(int mat[10][10], int i, int j, int num)
{
    for (int k=1; k<10; k++) {
        if (mat[i][k] == num || mat[k][j] == num) {
            return false;
        }
    }
    
    int p = (i/3)*3, q = (j/3)*3;
    
    for (int k=p; k<p+3; k++) {
        for (int l = q; l<q+3; l++) {
            if (mat[k][l] == num) {
                return false;
            }
        }
    }
    
    return true;
}




bool sudokuSolver(int mat[10][10], bool marked[10][10] ,int i, int j)
{
    //cout << " i =  "<<i<<"j= "<<j<<endl;
    
    if (i==9) {
        
        return true;
    }
    if (j==9) {
        return sudokuSolver(mat, marked, i+1,0);
    }
    
    if (marked[i][j] == false) {
        for (int k=1; k<10; k++)
        {
            if(isSafe(mat, i, j, k))
            {
                mat[i][j] = k;
                if( sudokuSolver(mat, marked,i,j+1) )
                    return true;
                
                mat[i][j] = 0;
            }
        }
        
        return false;
    }
    else
        return sudokuSolver(mat, marked, i, j+1);
}

int main()
{
    
    int mat[10][10] = {
        {8,0,0,7,5,0,0,4,0},
        {0,0,0,1,0,0,0,0,0},
        {5,1,0,4,0,6,0,0,7},
        {0,0,4,0,0,0,0,5,0},
        {1,0,5,0,0,0,7,0,8},
        {0,2,0,0,0,0,4,0,0},
        {0,0,0,9,0,2,0,6,1},
        {0,0,0,0,0,3,0,0,0},
        {0,0,0,0,6,1,0,0,5}};
    
    bool marked[10][10];
    
    for (int i=0; i<10; i++)
    {
        for (int j=0; j<10; j++) {
            if (mat[i][j] != 0) {
                marked[i][j] = true;
            }
            else
                marked[i][j] = false;
        }
    }
    
    sudokuSolver(mat,marked,0,0) ;
    //print
    
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            cout << mat[i][j] << " ";
        }
        cout<<endl;
    }
    
    
    
    return 0;
}



