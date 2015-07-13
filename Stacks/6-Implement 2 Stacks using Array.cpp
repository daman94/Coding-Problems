//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <stdlib.h>

#define SIZE 30
using namespace std;


//********************** Stack Functions ***********************************//

struct Stack
{
    int top1;
    int top2;
    
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
    
    S->capacity = SIZE;
    S->top1 = -1;
    S->top2 = SIZE;
    S->array = (int*)malloc(sizeof(int) * S->capacity);
    
    if (!S->array)
    {
        return NULL;
    }
    return S;
}

void Push1(struct Stack* S, int data)
{
    if (S->top2 > S->top1+1)
    {
        S->array[++S->top1] = data;
    }
    else
        cout << "Stack Overflow";
}

void Push2(struct Stack *S, int data)
{
    if (S->top2 > S->top1+1)
    {
        S->array[--S->top2] = data;
    }
    else
        cout << "Stack Overflow";
}

int Pop1(struct Stack* S)
{
    if (S->top1 == -1)
    {
        cout << "Stack is empty";
        return INT_MIN;
    }
    else
    {
        return (S->array[S->top1--]);
    }
}

int Pop2(struct Stack *S)
{
    if (S->top2 == SIZE)
    {
        cout << "Stack is empty";
        return INT_MIN;
    }
    else
    {
        return (S->array[S->top2++]);
    }
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

//*********************************************************//



//Main
int main()
{
    struct Stack *s = createStack();
    
    Push2(s, 1);
    Push2(s, 2);
    Push2(s, 3);
    
    cout << Pop2(s);
    
    DeleteStack(s);
    
    return 0;
}



































