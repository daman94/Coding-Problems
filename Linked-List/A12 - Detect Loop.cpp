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
void detectLoop(struct node* head);


struct node {
    int data;
    struct node* next;
};


//main
int main()
{
    struct node* head = NULL;
    
    for (int i=0; i<6; i++)
    {
        push(&head, 6-i);
    }
    
    
    
    /* Create a loop for testing */
    
    head->next->next->next->next->next->next = head->next->next;
    detectLoop(head);
    
    //printList(head);
    
    
    //printList(head);
    
    
    
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


void detectLoop(struct node* head)
{
    struct node* slow = head;
    struct node* fast = head;
    
    while (slow && fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        
        if (fast == slow)
        {
            cout << "Loop exists!";
            break;
        }
        
    }
    
    if (fast == slow)
    {
        fast = head;
        
        while (fast!= slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        cout << "The loop exits at: "<< slow->data;
    }
    
    else
        cout << "Loop does not exist..";
    
    
    
}








