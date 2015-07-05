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
int length(struct node* head);
void push(struct node** headRef, int data);
void recursiveReverse(struct node** headRef);


struct node {
    int data;
    struct node* next;
};


//main
int main()
{
    struct node* head = NULL;
    
    for (int i=1; i<4; i++)
    {
        push(&head, i);
    }
    
    printList(head);
    
    recursiveReverse(&head);
    
    printList(head);
    
    return 0;
}


//Functions

int length(struct node* head)
{
    int count = 0;
    struct node* current = head;
    while (current!= NULL)
    {
        count++;
        current = current->next;
    }
    
    return count;
}

void printList(struct node* head)
{
    cout << "The list is: ";
    
    struct node* current = head;
    while (current)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    
    cout << endl;
    
}

void push(struct node** headRef, int data)
{
    struct node* newNode = new node;
    newNode->data = data;
    
    newNode->next = *headRef;
    *headRef = newNode;
    
}

void recursiveReverse(struct node** headRef)
{
    struct node* first = *headRef;
    
    if (first==NULL)
    {
        return;
    }
    struct node* rest = first->next;
    if (rest==NULL)
    {
        return;
    }
    
    recursiveReverse(&rest);
    
    first->next->next = first;
    first->next = NULL;
    *headRef = rest;
    
    
}
































