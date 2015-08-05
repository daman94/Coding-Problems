//
//  main.c
//  Random C program
//
//  Created by Daman Saroa on 08/06/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <queue>
#include <list>
using namespace std;

class Graph
{
    int v;
    
    list <int> *l;
    
public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }
    
    void addEdge(int src, int dest)
    {
        l[src].push_back(dest);
    }
    
    void topologicalSort()
    {
        int arr[]= {0,0,0,0,0,0};
        
        
        for (int i=0; i<v; i++)
        {
            for (list<int> :: iterator it = l[i].begin(); it!=l[i].end(); it++)
            {
                arr[*it]++;
            }
        }
        
        queue<int> q;
        
        for (int i=0; i<v; i++)
        {
            if(arr[i] == 0)
                q.push(i);
        }
        
        while (!q.empty())
        {
            
            int temp = q.front();
            q.pop();
            cout << temp << " ";
            for (list<int> :: iterator it=l[temp].begin()  ; it!=l[temp].end()   ; it++)
            {
                arr[*it]--;
                if (arr[*it] == 0)
                {
                    q.push(*it);
                }
            }
        }
    }
};

int main()
{
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 3);
    g.addEdge(4, 1);
    g.addEdge(4, 3);
    g.addEdge(3, 2);
    g.addEdge(2, 1);
    
    g.topologicalSort();
    
    
    return 0;
}