//
//  main.cpp
//  Random C++ program
//
//  Created by Daman Saroa on 16/08/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
using namespace std;

int LCS[1024][1024]={0};

int LongestCommonSubsequence(char x[], char y[], int m, int n)
{
    for (int i=m-1; i>=0; i--)
    {
        for (int j=n-1; j>=0; j--)
        {
            LCS[i][j] = LCS[i+1][j+1];
            
            if (x[i] == y[j])
            {
                LCS[i][j]++;
            }
            
            LCS[i][j] = max(LCS[i][j], LCS[i+1][j] );
            LCS[i][j] = max(LCS[i][j], LCS[i][j+1]);
        }
    }
    
    return LCS[0][0];
}

void printSubsequence(char x[], char y[], int m, int n)
{
    int i=0, j=0;
    
    while (i<m && j<n)
    {
        if (x[i] == y[j]) cout << x[i];
        
        int p=i+1, q=j+1;
        if (LCS[i+1][j] == LCS[i][j])
        {
            p=i+1;
            q=j;
        }
        
        if (LCS[i][j+1] == LCS[i][j])
        {
            p=i;
            q=j+1;
        }
        
        
        i=p;
        j=q;
    }
    
}

int main()
{
    char x[] = "abcbdab";
    char y[] = "bdacba";
    
    int m = sizeof(x)/sizeof(x[0]);
    int n = sizeof(y)/sizeof(y[0]);
    
    m--;n--;
    
    cout << LongestCommonSubsequence(x, y, m, n) << endl;
    
    
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++) {
            cout<<LCS[i][j]<<" ";
        }
        
        cout<<endl;
    }
    
    cout << "Longest subsequence is: ";
    printSubsequence(x, y, m, n);
    
    return 0;
}