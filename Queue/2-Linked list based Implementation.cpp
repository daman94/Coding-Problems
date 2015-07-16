//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

//Queue Functions
struct node {
    int data;
    struct node* next;
};

struct Queue {
    struct node* front;
    struct node* rear;
};

struct Queue* createQueue()
{
    struct Queue* q;
    q = (struct Queue*)malloc(sizeof(struct Queue));
    
    if (!q) {
        return NULL;
    }
    
    q->front = q->rear = NULL;
    
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    
    if (!temp) {
        return NULL;
    }
    temp->next = NULL;
    
    return q;
}

int isEmptyQueue(struct Queue* q)
{
    return (q->front == NULL);
}

void EnQueue(struct Queue* q, int data)
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    if (!newNode) {
        return;
    }
    
    newNode->data = data;
    newNode->next = NULL;
    
    if (q->rear) {
        q->rear->next = newNode;
    }
    
    q->rear = newNode;
    
    if (isEmptyQueue(q)) {
        q->front = q->rear;
    }
}

int DeQueue(struct Queue* q)
{
    int data = INT_MIN;
    
    if (isEmptyQueue(q)) {
        cout << "Queue is empty";
        return data;
    }
    
    struct node* temp = q->front;
    q->front = q->front->next;
    data = temp->data;
    free(temp);
    
    return data;
}

void PrintQueue(struct Queue* q)
{
    struct node* current = q->front;
    while (current) {
        cout << current->data << "->";
        current = current->next;
    }
}

void DeleteQueue(struct Queue* q)
{
    if (!q) {
        cout << "Queue is deleted";
        return;
    }
    struct node* current = q->front;
    struct node* next = q->front;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    
    free(q);
}


int main()
{
    struct Queue* q = createQueue();
    
    EnQueue(q, 10);
    EnQueue(q, 11);
    EnQueue(q, 12);
    EnQueue(q, 15);
    
    
    PrintQueue(q);
    
    DeleteQueue(q);
    
    //DeleteQueue(q);
    
    return 0;
}








