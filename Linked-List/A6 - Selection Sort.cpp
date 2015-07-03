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
struct node* findMinAndRemove(struct node** start);
void selectionSort(struct node** headRef);

struct node {
    int data;
    struct node* next;
};


//main
int main()
{
    struct node* head = NULL;
    
    for (int i=0; i<3; i++)
    {
        push(&head, i);
    }
    
    printList(head);
    
    selectionSort(&head);
    
    
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

void selectionSort(struct node** headRef)
{
    struct node* current = *headRef;
    struct node* min = NULL;
    struct node* prev = NULL;
    
    if (current == *headRef)
    {
        min = findMinAndRemove(&current);
        *headRef = min;
        min->next = current;
        prev = *headRef;
    }
    
    while (current->next)
    {
        min = findMinAndRemove(&current);
        min->next = current;
        prev->next = min;
        prev = prev->next;
        //current = current->next;
    }
    
}

struct node* findMinAndRemove(struct node** start)
{
    struct node* current = *start;
    struct node* prev = NULL;
    struct node* min = current;
    
    while (current->next)
    {
        if (current->next->data < min->data)
        {
            prev = current;
            min = current->next;
        }
        
        current = current->next;
    }
    if (prev==NULL)
    {
        *start = min->next;
    }
    else
    {
        prev->next = prev->next->next;
    }
    min->next = NULL;
    return min;
}


























