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
void checkPalindrome(struct node** headRef);
void recReverse(struct node** headRef);

struct node {
    int data;
    struct node* next;
};


//main
int main()
{
    struct node* head = NULL;
    
    //    for (int i=0; i<6; i++)
    //    {
    //        push(&head, 6-i);
    //    }
    
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    
    
    
    printList(head);
    
    checkPalindrome(&head);
    
    
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

void checkPalindrome(struct node** headRef)
{
    struct node* fast = *headRef;
    struct node* slow = fast;
    
    while (fast && fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    struct node* mid = slow;
    
    recReverse(&(mid->next));
    
    struct node* first = *headRef;
    struct node* second = mid->next;
    
    while (first && second)
    {
        if (first->data == second->data)
        {
            first = first->next;
            second = second->next;
        }
        
        else
            break;
    }
    
    if ( (first == mid && second == NULL )|| (first==mid->next && second==NULL))
    {
        cout << " It is a Palindrome!";
        recReverse(&(mid->next));
        return;
    }
    
    cout << "Not a Palindrome";
    
    //construct original linked list
    
    recReverse(&(mid->next));
    return;
    
}

void recReverse(struct node** headRef)
{
    struct node* first = *headRef;
    if (first==NULL)
    {
        return;
    }
    
    struct node* rest = first->next;
    if (rest==NULL) {
        return;
    }
    
    recReverse(&rest);
    first->next->next = first;
    first->next = NULL;
    *headRef = rest;
    
}


























