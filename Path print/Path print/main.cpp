//
//  main.cpp
//  Path print
//
//  Created by Daman Saroa on 05/01/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
using namespace std;

/* bool func(char arr[][3] , int i , int j )
{
    if (i == 2 && j== 2)
    {
        arr[i][j] = '*';
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++) {
                cout << arr[i][j] << " ";
            }
            
            cout << endl;
        }
        
        cout<<endl;
        
        arr[i][j] = '.';
        
        return true;
    }

    
    arr[i][j] = '*';
    
    if (i+1 < 3) {
        return func(arr , i+1 , j );
    }
    if (j+1 < 3) {
        return func(arr , i , j+1);
    }
    
    //arr[i][j] = '.';
    
    return false;
}
*/
 
bool func(char arr[][4], int i, int j)
{
    if (i == 4 && j == 3) {
        arr[i][j] = '*';
        for (int i=0; i<4; i++)
        {
            for (int j=0; j<4; j++) {
                cout << arr[i][j] << " ";
            }
            
            cout << endl;
        }
        
        cout<<endl;
        
        arr[i][j] = '.';
        
        return true;
    }
    
    arr[i][j] = '*';
    
    if (i <= 4 && j+1 <= 3)
    {
        if (arr[i][j+1] == '.') {
            cout << "a called" << endl;
            return func(arr , i , j+1);
        }
    }
    
     if (i+1 <= 4 && j <= 3)
    {
        if (arr[i+1][j] == '.') {
            cout << "b called" << endl;

            return func(arr , i+1 , j);
        }
    }
    
    
     if (i-1 <= 4 && j <= 3)
    {
        if (arr[i-1][j] == '.') {
            cout << "c called" << endl;

            return func(arr , i-1 , j);
        }
    }
    
     if (i <= 4 && j-1 <= 3)
    {
        if (arr[i][j-1] == '.') {
            cout << "d called" << endl;

            return func(arr , i , j-1);
        }
    }

    
    arr[i][j] = '.';
    
    return false;
}


























int main()
{
    char arr[][4] = { {'.' , '.' , '.' , '.' },
                {'x' , 'x' , 'x', '.' },
                {'.' , '.' , '.' , '.' },
                {'.' , 'x' , 'x' , 'x' },
                {'.' , '.' , '.', '.' } };
    
    if(func(arr , 0 ,0)){
    cout << "true";
    }
    else cout << "false";
    
    
    
    return 0;
}