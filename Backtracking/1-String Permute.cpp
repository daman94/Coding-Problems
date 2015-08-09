//
//  main.cpp
//  Random C++ program
//
//  Created by Daman Saroa on 16/08/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include<string>
using namespace std;

void RecPermute(string soFar, string rest)
{
    if (rest.empty()) {
        cout<<soFar<<endl;
    }
    
    else
    {
        for (int i=0; i<rest.length(); i++) {
            string rem = rest.substr(0,i) + rest.substr(i+1);
            RecPermute(soFar+rest[i], rem);
        }
    }
}

int main()
{
    string s = "abcd";
    
    RecPermute("", s);
    
    
    return 0;
}


































