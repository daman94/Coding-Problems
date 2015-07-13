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
using namespace std;

void NextGreaterNumber(int *arr,int n)
{
    stack<int> s;
    
    int next, data;
    s.push(arr[0]);
    
    for (int i=1; i<n; i++) {
        next = arr[i];
        data = s.top();
        
        while (!s.empty() && next > s.top())
        {
            data = s.top();
            s.pop();
            cout << data << "->" << next << endl;
        }
        
        
        s.push(next);
    }
    
    while (!s.empty())
    {
        data = s.top();
        s.pop();
        next = -1;
        cout << data << "->" << next << endl;
    }
}

int main()
{
    int arr[] = {13,7,6,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    NextGreaterNumber(arr,n);
    
    return 0;
}