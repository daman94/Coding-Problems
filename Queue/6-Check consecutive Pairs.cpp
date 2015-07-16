//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stack>
#include <queue>
using namespace std;

bool consecutivePairs(stack<int> s)
{
    queue<int> q;
    int x, m, n;
    
    while (!s.empty())
    {
        x = s.top();
        s.pop();
        
        q.push(x);
    }
    
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        
        s.push(x);
    }
    
    while (!s.empty())
    {
        m = s.top();
        s.pop();
        q.push(m);
        
        if (!s.empty())
        {
            n = s.top();
            s.pop();
            q.push(n);
            
            if (abs(m-n) != 1) {
                return false;
            }
        }
    }
    
    while (!q.empty())
    {
        x = q.front();
        q.pop();
        s.push(x);
    }
    
    return true;
}

int main()
{
    stack<int> s;
    
    s.push(4);
    s.push(5);
    s.push(-2);
    s.push(-3);
    s.push(11);
    s.push(10);
    s.push(5);
    s.push(6);
    s.push(20);
    
    if (consecutivePairs(s) )
        cout << "COnsecutive";
    
    return 0;
}












































