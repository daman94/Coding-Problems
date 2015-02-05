//
//  Graph.h
//  Graphs
//
//  Created by Daman Saroa on 06/01/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#ifndef Graphs_Graph_h
#define Graphs_Graph_h
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

class Graph
{
    int** adjMat;
    int n;
    
private:
    void DFSHelper(int index,bool *visited ) {
        cout << index << " ";
        visited[index] = true;
        for(int i =0; i<n ; i++) {
            if(!visited[i] && adjMat[index][i] == 1) {
                DFSHelper(i , visited);
            }
        }
    }
public:
    Graph(int n)
    {
        this->n = n;
        
        adjMat = new int*[n];
        
        for (int i=0; i<n ; i++)
        {
            adjMat[i] = new int[n];
        }
        
        for (int i =0 ; i<n ; i++)
        {
            for (int j=0; j<n; j++)
            {
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
    
    void BFS()
    {
        bool visited[n];
        
        for (int i=0; i<n; i++) {
            
            visited[i] = false;
        }
        
        queue <int> q;
        
        for (int i=0; i<n; i++)
        {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
            
            while ( !q.empty() )
            {
                int u = q.front();
                cout << u << " ";
                
                q.pop();
                
                for (int v = 0; v<n; v++)
                {
                    if ( adjMat[u][v] == 1 && !visited[v] )
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
        bool visited[n] ;
        for(int i = 0; i<n ; i++)
        {
            visited[i] = false;
        }
        for(int i=0 ; i<n ; i++)
        {
            if(!visited[i])
            {
                DFSHelper(i,visited);
            }
        }
    }
    
    void TopologicalSort()
    {
        int indegree[n];
        
        for(int i=0;i<n;i++)
        {
            cout << "topo called" << endl;


            indegree[n] = 0;
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(adjMat[i][j] ==1)
                {
                    indegree[j]++ ;
                }
            }
        }
        
        queue<int> q;
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        } 
        
        while(!q.empty())
        {
            int u = q.front();
            cout << u << " ";
            q.pop();
            for(int v=0;v<n;v++)
            {
                if(adjMat[u][v] ==1)
                {
                    indegree[v]--;
                    if(indegree[v]==0)
                        q.push(v);
                }
            }
        }
        
    }
    

};






















#endif
