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

void EnQueue(struct Queue* q, int data)
{
    if (isFullQueue(q)) {
        cout << "Queue Overflow";
        return;
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
        return INT_MIN;
    }
    
    int data = q->array[q->rear];
    
    q->rear = (q->rear-1)%q->capacity;
    
    
    return data;
}









int main()
{
    
    return 0;
}