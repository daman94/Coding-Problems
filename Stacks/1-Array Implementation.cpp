//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
using namespace std;

struct Stack
{
    int top;
    int capacity;
    int* array;
};

struct Stack* createStack()
{
    struct Stack *S = (struct Stack*)malloc(sizeof(struct Stack));
    if (!S)
    {
        return NULL;
    }
    
    S->capacity = 1;
    S->top = -1;
    S->array = (int*)malloc(sizeof(int) * S->capacity);
    
    if (!S->array)
    {
        return NULL;
    }
    return S;
}

int isEmptyStack(struct Stack* S)
{
    return (S->top == -1);
}

int isFullStack(struct Stack* S)
{
    return (S->top == S->capacity-1);
}

void DoubleStack(struct Stack* S)
{
    S->capacity = S->capacity * 2;
    S->array = (int *)realloc(S->array, S->capacity);
}

void Push(struct Stack* S, int data)
{
    if (isFullStack(S))
    {
        DoubleStack(S);
    }
    
    S->array[++S->top] = data;
}

int Pop(struct Stack* S)
{
    if (isEmptyStack(S))
    {
        cout << "Stack is empty";
        return INT_MIN;
    }
    else
    {
        return (S->array[S->top--]);
    }
}

int Top(struct Stack* S)
{
    if (isEmptyStack(S))
    {
        return INT_MIN;
    }
    
    return S->array[S->top];
}

void DeleteStack(struct Stack* S)
{
    if (S)
    {
        if (S->array)
        {
            free(S->array);
        }
        
        free(S);
    }
}


//Main
int main()
{
    struct Stack* stack = createStack();
    
    Push(stack, 3);
    Push(stack, 2);
    Push(stack, 1);
    
    cout<<Pop(stack);
    
    DeleteStack(stack
                );
    
    return 0;
}



































