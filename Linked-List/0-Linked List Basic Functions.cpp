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
struct node* buildOneTwoThree();
void printList(struct node*);
int length(struct node* head);
void pushAtHead(struct node** headRef, int data);
void pushAtTail(struct node **headRef, int data);
struct node* addAtHead();
struct node* addAtTail();


struct node {
    int data;
    struct node* next;
};


//main
int main()
{
    struct node* head = buildWithDummyNode();
    
    
    printList(head);
    
    
    
    return 0;
}


//Functions
struct node* buildOneTwoThree()
{
    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;
    
    head = new struct node;
    second = new struct node;
    third = new struct node;
    
    head->data = 1;
    second->data = 2;
    third->data = 3;
    
    head->next = second;
    second->next = third;
    third->next = NULL;
    
    return head;
}

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

void pushAtTail(struct node **headRef, int data)
{
    struct node* newNode = new struct node;
    struct node* current = *headRef;
    
    if (current == NULL)
    {
        *headRef = newNode;
        newNode->data = data;
        newNode->next = NULL;
    }
    else
    {
        while (current->next != NULL)
        {
            current = current->next;
        }
        
        newNode->data = data;
        newNode->next = current->next;
        current->next = newNode;
    }
    
    
}

struct node* addAtHead()
{
    struct node* head = NULL;
    
    for (int i=1; i<=5; i++)
    {
        pushAtHead(&head, i);
    }
    
    return head;
}

struct node* addAtTail()
{
    struct node* head = NULL;
    
    for (int i=1; i<=5; i++)
    {
        pushAtTail(&head, i);
    }
    
    return head;
}





























