//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

struct AdjList
{
    struct node* head;
};

struct Graph
{
    int V;
    struct AdjList* array;
};

struct node* newNode(int data)
{
    struct node* newnode = new struct node;
    
    newnode->data = data;
    newnode->next = NULL;
    
    return newnode;
}

struct Graph* createGraph(int v)
{
    struct Graph* G = new struct Graph;
    
    G->V = v;
    
    G->array = (struct AdjList*) malloc(sizeof(struct AdjList) * v);
    
    for (int i=0; i<v; i++)
    {
        G->array[i].head = NULL;
    }
    
    return G;
}

void addEdge(struct Graph* G, int src, int dest)
{
    struct node* newnode = newNode(dest);
    
    newnode->next = G->array[src].head;
    
    G->array[src].head = newnode;
    
    //For Undirected graph
    
    newnode = newNode(src);
    newnode->next = G->array[dest].head;
    G->array[dest].head = newnode;
}

void PrintGraph(struct Graph* G)
{
    int v;
    for (v = 0; v < G->V; v++)
    {
        struct node* temp = G->array[v].head;
        
        printf("\n Adjacency list of vertex %d\n head ", v);
        
        while (temp)
        {
            printf("-> %d", temp->data);
            temp = temp->next;
        }
        
        printf("\n");
    }
}


int main()
{
    int V = 5;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    
    PrintGraph(graph);
    
    return 0;
}






















