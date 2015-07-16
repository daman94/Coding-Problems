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
struct Queue {
    int front;
    int rear;
    int capacity;
    int *array;
};

struct Queue* createQueue(int size)
{
    struct Queue* Q = (struct Queue*)malloc(sizeof(struct Queue));
    
    if (!Q)
    {
        return NULL;
    }
    
    Q->capacity = size;
    Q->array = (int*)malloc(sizeof(int) * Q->capacity);
    if (!Q->array)
    {
        return NULL;
    }
    
    Q->front = Q->rear = -1;
    
    return Q;
}

int isEmptyQueue(struct Queue* q)
{
    return (q->front == -1);
}

int isFullQueue(struct Queue* q)
{
    return ((q->rear+1)%q->capacity == q->front);
}

int QueueSize(struct Queue* Q)
{
    return ((Q->capacity - Q->front + Q->rear + 1)% Q->capacity ) ;
}

void ResizeQueue(struct Queue* q)
{
    int size = q->capacity;
    q->capacity = q->capacity * 2;
    
    q->array = (int *)realloc(q->array, q->capacity);
    
    if (q->front > q->rear)
    {
        for (int i=q->rear; i < q->front; i++)
        {
            q->array[i+size] = q->array[i];
        }
    }
    q->rear = q->rear+size;
}

void EnQueue(struct Queue* q, int data)
{
    if (isFullQueue(q)) {
        ResizeQueue(q);
    }
    q->rear = (q->rear+1) % q->capacity;
    q->array[q->rear] = data;
    
    if (q->front == -1)
    {
        q->front = q->rear;
    }
}

int DeQueue(struct Queue* q)
{
    if (isEmptyQueue(q))
    {
        cout << "Queue Underflow";
        return 0;
    }
    
    int data = q->array[q->front];
    
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    else
    {
        q->front = (q->front+1)%q->capacity;
    }
    
    return data;
}

void PrintQueue(struct Queue *q)
{
    if (isEmptyQueue(q))
    {
        cout << "Queue is empty";
        return;
    }
    
    int i = q->front;
    
    while (i != q->rear)
    {
        cout << q->array[i] << " ";
        
        i = (i+1)%q->capacity;
    }
    cout << q->array[i] << endl;
}

void DeleteQueue(struct Queue *q)
{
    if (q)
    {
        if (q->array)
        {
            free(q->array);
        }
        free(q);
    }
}


int main()
{
    struct Queue *Q = createQueue(3);
    
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    
    EnQueue(Q, 4);
    DeQueue(Q);
    
    PrintQueue(Q);
    
    
    DeleteQueue(Q);
    return 0;
}


































