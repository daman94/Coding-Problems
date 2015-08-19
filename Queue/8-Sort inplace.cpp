//
//  main.cpp
//  Random C++ program
//
//  Created by Daman Saroa on 16/08/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

void inplaceSort(queue<int> q)
{
    int n=0;
    
    
    
    q.push(-1);
    while (q.front() != -1)
    {
        int x = q.front();
        q.pop();
        q.push(x);
        n++;
    }
    
    q.pop();
    
    
    cout<<n<<endl;
    
    int j=n;
    
    
    while (j> 0)
    {
        int i=j;
        int min = INT_MAX;
        
        ///Find Minimum
        
        for (int i=0; i<j; i++)
        {
            if (q.front() < min)
            {
                min = q.front();
            }
            
            int x = q.front();
            q.pop();
            q.push(x);
        }
        
        cout<<"min is: "<<min << "      ";
        
        for (int i=j; i<n; i++)
        {
            q.push(q.front());
            q.pop();
        }
        
        //reordering queue
        
        for (int i=0; i<n; i++)
        {
            if (q.front()==min)
            {
                q.pop();
            }
            else
            {
                q.push(q.front());
                q.pop();
            }
        }
        
        q.push(min);
        
        for (int i=0;i<n; i++)
        {
            cout << q.front();
            q.push(q.front());
            q.pop();
        }
        cout<<endl;
        
        j--;
    }
    
    
    
    
}



int main()
{
    queue<int> q;
    
    q.push(4);
    q.push(3);
    //q.push(1);
    q.push(2);
    q.push(6);
    q.push(5);
    
    
    inplaceSort(q);
    
    
    
    return 0;
}