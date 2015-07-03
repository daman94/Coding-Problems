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

void insertAtIndex(struct node** headRef, int data, int index)
{
    if (index == 0)
    {
        push(headRef, data);
    }
    else{
        struct node* current = *headRef;
        
        while (index!=1)
        {
            if (current->next != NULL)
            {
                current = current->next;
                index--;
            }
            else
            {
                cout << "Index out of domain";
                break;
            }
        }
        struct node* newNode = new node;
        newNode->data = data;
        newNode->next = current->next;
        current->next = newNode;
    }
}

void deleteNode(struct node** headRef, int key)
{
    if (*headRef == NULL)
    {
        cout<<"Empty list";
    }
    
    struct node* current = *headRef;
    if (current->data == key)
    {
        *headRef = current->next;
        free(current);
    }
    
    else
    {
        struct node* prev = NULL;
        
        while (current->data != key)
        {
            prev = current;
            if (current->next == NULL)
            {
                cout << "key not available";
                break;
            }
            current = current->next;
        }
        
        prev->next = current->next;
        free(current);
    }
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


































