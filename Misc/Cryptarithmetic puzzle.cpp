//
//  main.cpp
//  Random C++ program
//
//  Created by Daman Saroa on 16/08/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, int> m;
map<int, bool> assigned;

bool satisfyExpression(string exp)
{
    int i=0;
    int num1=0, num2=0, num3=0;
    
    while ( isalpha(exp[i]) )
    {
        num1= num1*10 + m[exp[i]];
        i++;
    }
    
    i++;
    
    while ( isalpha(exp[i]) )
    {
        num2= num2*10 + m[exp[i]];
        i++;
    }
    
    i++;
    
    while ( isalpha(exp[i]) )
    {
        num3= num3*10 + m[exp[i]];
        i++;
    }
    cout << num1 << " " <<num2 << " " << num3 << endl;
    return (num1 + num2 == num3);
}

bool solve(string str, string expression)
{
    if (str.empty() && satisfyExpression(expression)) return true;
    
    for (int num=0; num<=9; num++)
    {
        if (!assigned[num])
        {
            m[str[0]] = num;
            assigned[num] = true;
            
            bool ok = solve(str.substr(1), expression);
            
            if (ok)
                return true;
            else
            {
                m[str[0]] = -1;
                assigned[num] = false;
            }
        }
        
    }
    
    return false;
}

int main()
{
    string s = "sendmory";
    string exp = "send+more=money";
    
    int i=0;
    
    for (int i=0; i<=9; i++) {
        assigned[i] = false;
    }
    
    
    while (s[i] != '\0')
    {
        m[s[i]] = -1;
        
        i++;
    }
    
    
    if (solve(s, exp))
    {
        for (i=0; i<s.length(); i++)
        {
            cout << s[i] << " = " << m[s[i]]<<endl;
        }
    }
    
    return 0;
}




















