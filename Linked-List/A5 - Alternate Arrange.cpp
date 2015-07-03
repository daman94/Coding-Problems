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
void alternateArrange(struct node* head);


struct node {
    int data;
    struct node* next;
};


//main
int main()
{
    struct node* head = NULL;
    
    for (int i=0; i<8; i++)
    {
        push(&head, 6-i);
    }
    
    printList(head);
    
    alternateArrange(head);
    
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

void alternateArrange(struct node* head)
{
    struct node* fast = head;
    struct node* mid = head;
    
    while (fast)
    {
        fast = fast->next->next;
        mid = mid->next;
    }
    
    struct node* current = head;
    struct node* next1 = NULL;
    struct node* next2 = NULL;
    
    while (mid->next)
    {
        next1 = current->next;
        next2 = mid->next;
        
        current->next = mid;
        mid->next = next1;
        
        current = next1;
        mid = next2;
    }
    current->next = mid;
    mid->next = NULL;
    
}





































