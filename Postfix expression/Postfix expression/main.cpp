//
//  main.cpp
//  Postfix expression
//
//  Created by Daman Saroa on 20/12/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

int precedence(char ch)
{
    return (ch == '+' || ch == '-') ? 1:2 ;
}

void convert_Infix_To_Postfix(string p)
{
    stack<char> s;
    
    int i=0;
    
    while (p[i] != '\0')
    {
        if (p[i] >= 48 && p[i] <= 57)
        {
            cout<<p[i];
        }
        
        else if( s.empty() || precedence(s.top()) <= precedence(p[i]) )
        {
            s.push(p[i]);
        }
        else
        {
            while (!s.empty() || precedence(s.top()) >= precedence(p[i]) )
            {
                cout<<p[i];
                s.pop();
            }
            
            s.push(p[i]);
        }
        
        i++;
    }
    
    while (!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
    
}

int main()
{

    string p;
    cin>>p;
    
    convert_Infix_To_Postfix(p);
}
