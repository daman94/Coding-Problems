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
#include <ctype.h>
using namespace std;


//********************** Stack Functions ***********************************//

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

//*********************************************************//

void evaluatePostfix(char *exp)
{
    struct Stack* s = createStack();
    if (!s)
    {
        cout << "stack not found";
        return ;
    }
    
    int i=0;
    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]))
        {
            Push(s, exp[i]-'0' );
        }
        
        else
        {
            int a,b;
            a = Pop(s);
            b = Pop(s);
            
            switch (exp[i])
            {
                case '+':
                    Push(s, b+a);
                    break;
                    
                case '-':
                    Push(s, b-a);
                    break;
                    
                case '*':
                    Push(s, b*a);
                    break;
                    
                case '/':
                    Push(s, b/a);
                    break;
                    
                case '^':
                    Push(s, b^a);
                    break;
                    
            }
        }
        
        i++;
    }
    
    if (!isEmptyStack(s))
    {
        cout << "the value is : "<<Pop(s);
    }
    
    DeleteStack(s);
    return;
}

//Main
int main()
{
    char exp[] = "231*+9-";
    
    evaluatePostfix(exp);
    return 0;
}



































