//
//  main.c
//  Random C program
//
//  Created by Daman Saroa on 08/06/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void RabinKarp(string s, string p)
{
    int h = p[0] - '0';
    
    for (int i=1; i<p.length(); i++) {
        h = h*10+(p[i] - '0');
    }
    
    int k = 2*(s[0]-'0');
    for (int i=1; i<s.length(); i++) {
        k = k-((s[i-1]-'0') * pow(10, p.length()-1));
        cout<<k<<endl;
        
        for (int j=1; j<p.length(); j++) {
            k = k*10+(s[j]-'0');
        }
        
        
        
        if (h==k) {
            int m=0;
            while (p[m]!='\0' && s[i] == p[m]) {
                i++;
                m++;
            }
            
            if (m == p.length()) {
                cout << "pattern found";
                break;
            }
        }
    }
    
}

int main()
{
    string p = "89";
    string s = "780903123523896";
    
    
    RabinKarp(s, p);
    
    return 0;
}