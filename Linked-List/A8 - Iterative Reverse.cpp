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
void reverse(struct node** headRef);

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
    
    reverse(&head);
    
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

void reverse(struct node** headRef)
{
    struct node* prev = *headRef;
    struct node* mid = prev->next;
    if (mid == NULL)
    {
        return;
    }
    struct node* next = mid->next;
    
    prev->next = NULL;
    
    while (next!=NULL)
    {
        mid->next = prev;
        prev = mid;
        mid = next;
        next = next->next;
    }
    
    mid->next = prev;
    *headRef = mid;
}


































