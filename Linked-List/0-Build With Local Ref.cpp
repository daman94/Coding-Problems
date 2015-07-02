//
//  main.c
//  Random C program
//
//  Created by Daman Saroa on 08/06/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

//Functions
void printList(struct node*);
void pushAtHead(struct node** headRef, int data);
struct node* buildWithLocalRef();

struct node {
    int data;
    struct node* next;
};


//main
int main()
{
    struct node* head = buildWithLocalRef();
    
    
    printList(head);
    
    
    
    return 0;
}


//Functions
void printList(struct node* head)
{
    struct node* current = head;
    while (current)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
}

void pushAtHead(struct node** headRef, int data)
{
    struct node* newNode = new struct node;
    
    newNode->data = data;
    newNode->next = *headRef;
    
    *headRef = newNode;
    
}

struct node* buildWithLocalRef()
{
    struct node* head = NULL;
    struct node** lastPtrRef = &head;
    
    for (int i=1; i<=5; i++)
    {
        pushAtHead(lastPtrRef, i);
        lastPtrRef = &((*lastPtrRef)->next);
    }
    
    return head;
}





























