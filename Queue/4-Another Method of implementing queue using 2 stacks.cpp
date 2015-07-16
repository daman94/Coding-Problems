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

struct stack {
    int data;
    struct stack* next;
};

struct queue {
    struct stack* s1;
    struct stack* s2;
};

struct stack* createStack()
{
    return NULL;
}

bool isEmptyStack(struct stack* S)
{
    return (S==NULL)? true: false;
}

void push(struct stack** headRef, int data)
{
    struct stack* newNode = (struct stack*)malloc(sizeof(struct stack));
    newNode->data = data;
    newNode->next = *headRef;
    
    *headRef = newNode;
}

int top(struct stack* s)
{
    if (isEmptyStack(s)) {
        return INT_MIN;
    }
    return s->data;
}

int pop(struct stack** headRef)
{
    if (isEmptyStack(*headRef))
    {
        cout << "Stack is empty";
        return INT_MIN;
    }
    
    struct stack* node = *headRef;
    int data = node->data;
    
    *headRef = node->next;
    free(node);
    return data;
}

void DeleteStack(struct stack** headRef)
{
    struct stack* current = *headRef;
    struct stack* temp = *headRef;
    
    while (current)
    {
        temp = current->next;
        free(current);
        current = temp;
    }
}

bool EnQueue(struct queue* q ,int data)
{
    push(&(q->s1), data);
    return true;
}

bool DeQueue(struct queue* q, int &data)
{
    if (!isEmptyStack(q->s2)) {
        data = pop(&(q->s2));
        return true;
    }
    
    while (!isEmptyStack(q->s1))
    {
        push(&(q->s2), pop(&(q->s1)) );
    }
    
    if (isEmptyStack(q->s2)) {
        return false;
    }
    
    data = pop(&(q->s2));
    return true;
}

bool isEmptyQueue(struct queue* q)
{
    return (isEmptyStack(q->s1) && isEmptyStack(q->s2));
}

void DeleteQueue(struct queue* q)
{
    if (q->s1)
    {
        DeleteStack(&(q->s1));
    }
    
    if (q->s2)
    {
        DeleteStack(&(q->s2));
    }
    
    free(q);
}

int main()
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    
    // this or simply struct queue *q; works????????????
    
    
    q->s1 = NULL;
    q->s2 = NULL;
    EnQueue(q, 1);
    EnQueue(q, 2);
    EnQueue(q, 3);
    
    int data;
    
    while (!isEmptyQueue(q)) {
        DeQueue(q, data);
        cout << data;
    }
    
    return 0;
}























































