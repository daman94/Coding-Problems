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

void ReverseKElements(queue<int> &q, int k)
{
    stack<int> s;
    int size = q.size();
    int x;
    
    for (int i=0; i<k; i++)
    {
        x = q.front();
        q.pop();
        s.push(x);
    }
    
    while (!s.empty())
    {
        x = s.top();
        s.pop();
        q.push(x);
    }
    
    
    for (int i=0; i<size-k; i++)
    {
        x = q.front();
        q.pop();
        q.push(x);
    }
}


int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    
    ReverseKElements(q, 4);
    
    
    while (!q.empty())
    {
        cout << q.front() <<" ";
        q.pop();
    }
    
    
    return 0;
}

