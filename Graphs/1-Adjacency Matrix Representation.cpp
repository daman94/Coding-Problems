//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

struct Graph
{
    int V;
    int E;
    int** Adj;
};

struct Graph* adjMatrixOfGraph()
{
    int i,u,v;
    
    struct Graph* G = new struct Graph;
    
    if (!G)
    {
        cout << "Memory error";
        return NULL;
    }
    
    cout << "No. of vertices";
    cin >> G->V;
    cout << "No. of edges";
    cin >> G->E;
    
    G->Adj = (int**)malloc(sizeof(G->V * G->V));
    
    for (u=0; u < G->V; u++)
    {
        for (v=0; v < G->V; v++)
        {
            G->Adj[u][v] = 0;
        }
        
        for (i=0; i<G->E; i++)
        {
            cout << "reading edge: ";
            cin >> u >> v;
            G->Adj[u][v] = 1;
            G->Adj[v][u] = 1;
        }
    }
    
    return G;
    
}


int main()
{
    struct Graph* G;
    
    G = adjMatrixOfGraph();
    
    return 0;
}


























