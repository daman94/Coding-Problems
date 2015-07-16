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

//Doubly ended queues

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

void PushBackDEQ(struct node** headRef, int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    
    if (*headRef==NULL)
    {
        *headRef = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    
    else
    {
        newNode->next = *headRef;
        newNode->prev = (*headRef)->prev;
        (*headRef)->prev->next = newNode;
        (*headRef)->prev = newNode;
    }
}

void PushFrontDEQ(struct node** headRef, int data)
{
    PushBackDEQ(headRef, data);
    *headRef = (*headRef)->prev;
}

int PopBackDEQ(struct node** headRef)
{
    int data;
    struct node* temp = (*headRef)->prev;
    data = temp->data;
    
    if (temp == *headRef)
    {
        *headRef = NULL;
    }
    
    else
    {
        temp->prev->next = *headRef;
        (*headRef)->prev = temp->prev;
    }
    
    free(temp);
    return data;
}

int PopFrontDEQ(struct node** headRef)
{
    int data;
    *headRef = (*headRef)->next;
    data = PopBackDEQ(headRef);
    
    return data;
}

int isEmptyDEQ(struct node* head)
{
    return (head == NULL);
}

int main()
{
    struct node* DEQHead = NULL;
    
    PushFrontDEQ(&DEQHead, 1);
    PushFrontDEQ(&DEQHead, 2);
    PushBackDEQ(&DEQHead, 3);
    PushFrontDEQ(&DEQHead, 4);
    
    while (!isEmptyDEQ(DEQHead)) {
        cout << PopFrontDEQ(&DEQHead);
    }
    
    return 0;
}



























