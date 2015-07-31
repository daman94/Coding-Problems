
//
//  main.cpp
//  Random C++ program
//
//  Created by Daman Saroa on 03/08/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
using namespace std;

int LCS(char x[], char y[], int i, int j, int m, int n)
{
    if (m==0 || n==0 || i==m || j==n)
        return 0;
    
    if (x[i] == y[j])
        return (1+ LCS(x, y, i+1, j+1, m, n));
    
    return max(LCS(x, y, i+1, j, m, n), LCS(x, y, i, j+1, m, n));
}

int main()
{
    char str1[] = "abcdab";
    char str2[] = "bdcbadb";
    
    int m = sizeof(str1)/sizeof(str1[0]);
    int n = sizeof(str2)/sizeof(str2[0]);
    
    //cout << m << "   " << n;
    
    cout << LCS(str1, str2, 0, 0, m-1, n-1);
    
    return 0;
}