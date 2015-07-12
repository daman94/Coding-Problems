//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <limits.h>
using namespace std;

struct stack {
    int data;
    struct stack* next;
};

struct stack* Create()
{
    return NULL;
}

void Push(struct stack **topRef, int data)
{
    struct stack* temp;
    temp = (struct stack*)malloc(sizeof(struct stack));
    
    if (!temp)
    {
        return;
    }
    
    temp->data = data;
    temp->next = *topRef;
    *topRef = temp;
}

int isEmptyStack(struct stack* top)
{
    return (top == NULL);
}

int Pop(struct stack **topRef)
{
    struct stack *temp = *topRef;
    int data = temp->data;
    if (isEmptyStack(*topRef))
    {
        cout << "stack is empty";
        return INT_MIN;
    }
    
    *topRef = (*topRef)->next;
    free(temp);
    
    return data;
}

int Top(struct stack* top)
{
    if (isEmptyStack(top))
    {
        return INT_MIN;
    }
    
    return top->data;
}

void DeleteStack(struct stack** topRef)
{
    struct stack* temp = *topRef;
    struct stack* p = temp;
    
    while (p)
    {
        p = p->next;
        free(temp);
        temp = p;
    }
}


//Main
int main()
{
    struct stack* top = NULL;
    
    Push(&top, 1);
    Push(&top, 2);
    Push(&top, 3);
    
    cout << Pop(&top);
    
    return 0;
}



















