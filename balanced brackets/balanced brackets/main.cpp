//
//  main.cpp
//  balanced brackets
//
//  Created by Daman Saroa on 20/12/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

bool checkBalancedBrackets (char p[])
{
    stack<char> s;
    int i=0;
    
    while (p[i] != '\0')
    {
        if ( p[i] == '(' || p[i] == '{' || p[i] == '[')
        {
            s.push(p[i]);
            i++;
        }
        
        else
        {
            switch (p[i])
            {
                case ')':
                    if (!s.empty())
                    {
                        if (s.top() == '(')
                        {
                            s.pop();
                            i++;
                        }
                    }
                    
                    else return false;
                    break;
                    
                case ']':
                    if (!s.empty())
                    {
                        if (s.top() == '[')
                        {
                            s.pop();
                            i++;
                        }
                    }
                    else return false;
                    break;
                    
                case '}':
                    if (!s.empty())
                    {
                        if (s.top() == '{')
                        {
                            s.pop();
                            i++;
                        }
                    }
                    else return false;
                    break;
                    
                default:
                    i++;
                    break;
            }
        }
    }
    
    
    if (s.empty())
    {
        return true;
    }
    
    else
        return false;
    
}

int main()
{
    char p[1000];
    cin>>p;
    
    if(checkBalancedBrackets(p) == true)
        cout<<"Balanced"<<endl;
    
    else
        cout<<"NOT BALANCED"<<endl;
    
    
    return 0;
}