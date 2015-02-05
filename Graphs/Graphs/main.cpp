//
//  main.cpp
//  Graphs
//
//  Created by Daman Saroa on 02/01/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include "Graph.h"
using namespace std;

class graph {
    vector < list <int> > aList;
     void DFSUtil(vector <bool> & visited, int v)
    {
        cout << v << endl;
        visited[v] = true;
        
        list<int>::iterator it;
        
        for (it = aList[v].begin() ; it!= aList[v].end() ; it++)
        {
            if (visited[*it] != true)
            {
                DFSUtil(visited, *it);
            }
        }
    }
public:
    explicit graph(int v)
    {
        aList.resize(v);
    }
    
    bool addEdge(int src, int dest)
    {
        if (find(aList[src].begin(), aList[src].end() , dest) != aList[src].end())
        {
            return false;
        }
        
        aList[src].push_back(dest);
        return true;
    }
    
    void DFS()
    {
        vector<bool> visited;
        for (int i=0; i < aList.size() ; i++)
        {
            visited.push_back(false);
        }
        
        for (int i=0; i < aList.size() ; i++)
        {
            if (!visited[i])
            {
                DFSUtil(visited, i);
            }
        }
    }
    
    void BFS()
    {
        vector<bool> visited(aList.size(), false);
        queue<int> q;
        
        for (int i=0; i < aList.size() ; i++)
        {
            if(visited[i] != true)
            {
                q.push(0);
                visited[0] = true;
                
                while (!q.empty())
                {
                    int v = q.front();
                    q.pop();
                    cout << v << endl;
                    
                    list<int>::iterator it;
                    
                    for (it = aList[v].begin() ; it!= aList[v].end() ; it++)
                    {
                        if (visited[*it] != true)
                        {
                            visited[*it] = true;
                            q.push(*it);
                        }
                    }
                    
                }
                
            }
        }
        
        
    }
};

int main()
{
    /* graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,3);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(3,2);
    g.addEdge(4,2);


    g.DFS();
    
    g.BFS();
    */
    
   /* Graph g(5);
    
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(2, 3);
    //g.addEdge(4, 1);
    
    //g.BFS();
    
    g.DFS();
    
    */
    
    Graph g2(6);
    g2.addEdge(5, 2);
    g2.addEdge(5, 0);
    g2.addEdge(4, 0);
    g2.addEdge(4, 1);
    g2.addEdge(2, 3);
    g2.addEdge(3, 1);
    
    g2.TopologicalSort();
    
    return 0;
}



































