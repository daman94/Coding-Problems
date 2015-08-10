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

string FindWord(string soFar, string rest, string word)
{
    if (rest.empty()) {
        return (word == soFar)? soFar:"";
    }
    
    else {
        for (int i=0; i<rest.length(); i++) {
            string rem = rest.substr(0,i) + rest.substr(i+1);
            string found = FindWord(soFar+rest[i], rem, word);
            if (!found.empty()) {
                return found;
            }
        }
        return "";
    }
}

int main()
{
    string s = "nadam";
    string word = "daman";
    
    cout << FindWord("", s, word);
    
    return 0;
}


































