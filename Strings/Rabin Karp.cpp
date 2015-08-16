//
//  main.cpp
//  Random C++ program
//
//  Created by Daman Saroa on 16/08/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void RabinKarpPatternMatching(string str, string p)
{
    int strIndex=0;
    
    int np = (int)p.length();
    int ns = (int)str.length();
    
    int h=0; // hash func for pattern
    for (int i=0; i<np; i++)
    {
        h = h*10 + (p[i]-'0');
    }
    
    
    for (int i=0; i<=ns-np; i++)
    {
        int k=0;   //hash func for string
        
        for (int j=i; j<i+np; j++)
        {
            k = k*10 + (str[j]-'0');
        }
        
        if (k==h)
        {
            int pIndex=0, sIndex=i;
            while (p[pIndex] != '\0' && p[pIndex] == str[sIndex])
            {
                pIndex++;
                sIndex++;
            }
            
            if (p[pIndex] == '\0')
            {
                cout << "Pattern found at index: " << i << endl;
            }
        }
    }
    
}

int main()
{
    string p = "87";
    string str = "188728787187";
    
    RabinKarpPatternMatching(str, p);
    
    return 0;
}