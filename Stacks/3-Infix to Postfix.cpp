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


//********************** Stack Functions ***********************************//

struct Stack
{
    char top;
    int capacity;
    char* array;
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
    S->array = (char*)malloc(sizeof(int) * S->capacity);
    
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
    S->array = (char *)realloc(S->array, S->capacity);
}

void Push(struct Stack* S, char data)
{
    if (isFullStack(S))
    {
        DoubleStack(S);
    }
    
    S->array[++S->top] = data;
}

char Pop(struct Stack* S)
{
    if (isEmptyStack(S))
    {
        cout << "Stack is empty";
        return NULL;
    }
    else
    {
        return (S->array[S->top--]);
    }
}

char Top(struct Stack* S)
{
    if (isEmptyStack(S))
    {
        return NULL;
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

int isOperand(char ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') );
}

int prec(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
            return 1;
            break;
            
        case '*':
        case '/':
            return 2;
            break;
            
        case '^':
            return 3;
            
        default:
            return -1;
            break;
    }
}

void infixToPostfix(char *exp)
{
    int i,k;
    
    struct Stack *S = createStack();
    if (!S)
    {
        return;
    }
    
    i=0;
    while (exp[i])
    {
        if (isOperand(exp[i]))
        {
            cout << exp[i];
        }
        
        else if (exp[i] == '(')
            Push(S, exp[i]);
        
        else if (exp[i] == ')' && !isEmptyStack(S))
        {
            while (Top(S) != '(')
            {
                cout << Pop(S);
            }
            Pop(S);
        }
        
        else                //Operator
        {
            while (prec(exp[i]) <= prec(Top(S)) && !isEmptyStack(S) )
            {
                cout << Pop(S);
            }
            Push(S, exp[i]);
            
        }
        
        i++;
    }
    
    while (!isEmptyStack(S))
    {
        cout << Pop(S);
    }
    
}


//Main
int main()
{
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    
    infixToPostfix(exp);
    
    
    return 0;
}



































