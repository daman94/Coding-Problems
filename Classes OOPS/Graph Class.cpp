//
//  main.cpp
//  Random C++ program
//
//  Created by Daman Saroa on 16/08/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <queue>
using namespace std;

class Graph
{
    int V;
    int** arr;
    
public:
    Graph(int V)
    {
        this->V = V;
        
        arr = new int*[V];
        
        for (int i=0; i<V; i++)
        {
            arr[i] = new int[V];
        }
        
        for (int i=0; i<V; i++)
        {
            for (int j=0; j<V; j++)
            {
                arr[i][j] = 0;
            }
        }
    }
    
    void addEdge(int u, int v)
    {
        arr[u][v] = 1;
    }
    
    void BFS()
    {
        queue<int> q;
        bool visited[V];
        
        for (int i=0; i<V; i++)
        {
            visited[i] = false;
        }
        
        for (int i=0; i<V; i++)
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
            
            while (!q.empty())
            {
                int u = q.front();
                cout << u << " ";
                q.pop();
                
                //adjacent vertices
                for (int v=0; v<V; v++)
                {
                    if (!visited[v] && arr[u][v] == 1)
                    {
                        q.push(v);
                        visited[v] = true;
                    }
                }
            }
        }
    }
    
    void DFS()
    {
        
    }
};



int main()
{
    Graph g(6);
    
    g.addEdge(0, 5);
    g.addEdge(1, 3);
    g.addEdge(2, 1);
    g.addEdge(2, 0);
    g.addEdge(3, 4);
    g.addEdge(3, 2);
    g.addEdge(4, 1);
    g.addEdge(4, 2);
    g.addEdge(5, 1);
    g.addEdge(5, 3);
    
    g.BFS();
    
    return 0;
}





















