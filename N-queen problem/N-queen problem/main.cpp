//
//  main.cpp
//  N-queen problem
//
//  Created by Daman Saroa on 06/01/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
using namespace std;

bool isSafe(char arr[][5] , int i , int j)
{
    for (int k=0; k<5; k++) {
        if (arr[i][k] == 'Q') {
            return false;
        }
        
        if (i-k >= 0 && j-k <=5) {
            if (arr[i-k][j-k] == 'Q') {
                return false;
            }
        }
        if (i+k >= 0 && j+k <= 5)
        {
            if (arr[i+k][j+k] == 'Q') {
                return false;
            }
        }
    }

    return true;
}

bool func(char arr[][5] ,int n,  int i , int j )
{
    if ( j > 4)
    {
        for (int m=0; m<5; m++) {
            for (int k=0; k<5; k++) {
                cout << arr[m][k] << " " ;
            }
            cout << endl;
        }
        
        return true;
    }
    
    for (int a=0; a<5; a++) {
        if (isSafe(arr, a ,j) )
        {
            arr[a][j] = 'Q';
            
            if (func(arr, n, 0, j+1) )
                return true;
            
            arr[a][j] = '.';
        }
    }
    return false;
}

int main()
{
//    int n;
//    cout << " Enter number :";
//    cin >> n;
   char arr[5][5] ;
    
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            arr[i][j] = '.';
        }
    }
    
   if( func(arr , 5, 0, 0) )
       cout << "truw\e";
    else cout <<"false";
    
    return 0;
}