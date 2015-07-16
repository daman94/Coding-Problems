//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

stack<int> S1;
stack<int> S2;

bool EnQueue(int data)
{
    S1.push(data);
    return true;
}

bool DeQueue(int &value)
{
    int data;
    
    if (!S2.empty()) {
        value = S2.top();
        S2.pop();
        return true;
    }
    
    while (!S1.empty()) {
        data = S1.top();
        S1.pop();
        S2.push(data);
    }
    
    if (S2.empty()) {
        return false;
    }
    
    value = S2.top();
    S2.pop();
    return true;
}

bool isEmptyQueue()
{
    return (S1.empty() && S2.empty()) ? true:false;
}



int main()
{
    EnQueue(1);
    EnQueue(2);
    EnQueue(3);
    EnQueue(4);
    EnQueue(5);
    
    
    int value;
    
    DeQueue(value);
    EnQueue(6);
    
    while (!isEmptyQueue())
    {
        DeQueue(value);
        cout<<value<<" ";
    }
    
    
    return 0;
}





































