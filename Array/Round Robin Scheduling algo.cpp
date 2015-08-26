//
//  main.cpp
//  Random C++ program
//
//  Created by Daman Saroa on 16/08/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <queue>
#include <map>
using namespace std;

void roundRobin(int *arr, int *burst, int q)
{
    queue<int> myQ;
    map<int, bool> myQueueMap;
    map<int, bool> myFirstArrivalMap;
    
    int start[6], end[6], waiting[6];
    
    myQ.push(0);
    
    for (int i=0; i<=6; i++) {
        waiting[i] = 0;
        myQueueMap[i] = false;
        myFirstArrivalMap[i] = true;
    }
    
    int i=0;
    
    myQueueMap[0] = true;
    
    
    
    while (!myQ.empty())
    {
        int p = myQ.front();
        myQ.pop();
        
        if (burst[p] < q)
        {
            start[p] = i;
            
            // cout << p+1 <<" start: "<<start[p] << " end: " << end[p]<<endl;
            
            if (!myFirstArrivalMap[p])
            {
                waiting[p] += (start[p] - end[p]);
            }
            end[p] = i+burst[p];
            i = end[p];
            burst[p] = 0;
        }
        
        else
        {
            start[p] = i;
            
            //cout << p <<" start: "<<start[p] << " end: " << end[p]<<endl;
            
            if (!myFirstArrivalMap[p])
            {
                waiting[p] += (start[p] - end[p]);
            }
            end[p] = i+q;
            i = i+q;
            burst[p] -= q;
        }
        
        if (myFirstArrivalMap[p] ==  true)
        {
            myFirstArrivalMap[p] = false;
            waiting[p] = start[p] - arr[p];
        }
        
        //  cout<<"starting time of p: "<<p+1<<" is: "<<start[p]<<endl;
        
        
        //push to queue
        
        int ending_time = end[p];
        for (int j=0; j<6; j++) {
            if (myQueueMap[j] == false && arr[j] <= ending_time)
            {
                myQueueMap[j] = true;
                myQ.push(j);
            }
        }
        
        if (burst[p] != 0) {
            myQ.push(p);
        }
        
    }
    
    for (int j=0; j<6; j++)
    {
        cout << waiting[j] << " ";
    }
}

int main()
{
    int arrival[] = {0,1,2,4,6,7};
    int burst[] = {4,5,6,1,3,2};
    
    int quantum = 2;
    
    roundRobin(arrival, burst, quantum);
    
    return 0;
}







