//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
using namespace std;

class Graph
{
    int V;
    int** adjMat;
    
public:
    Graph(int n)
    {
        this->V = n;
        
        adjMat = new int* [n];
        
        for (int i=0; i<n; i++)
        {
            adjMat[i] = new int[n];
        }
        
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++) {
                adjMat[i][j] = 0;
            }
        }
    }
    
    void addEdge(int u, int v)
    {
        adjMat[u][v] = 1;
    }
    
    void deleteEdge(int u, int v)
    {
        adjMat[u][v] = 0;
    }
    
};

int main()
{
    Graph g(4);
    
    
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    
    
    return 0;
}



