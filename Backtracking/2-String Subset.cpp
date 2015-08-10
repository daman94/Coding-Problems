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

void RecSubset(string soFar, string rest)
{
    if (rest.empty()) {
        cout << soFar << endl;
    }
    
    else{
        RecSubset(soFar+rest[0], rest.substr(1));
        RecSubset(soFar, rest.substr(1));
    }
}

int main()
{
    string s = "abcd";
    
    RecSubset("", s);
    
    return 0;
}


































