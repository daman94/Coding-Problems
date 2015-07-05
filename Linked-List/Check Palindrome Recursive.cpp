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
bool palindromeUtility(struct node** left, struct node* right);
void checkPalindrome(struct node* head);



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
    
    checkPalindrome(head);
    
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


void checkPalindrome(struct node* head)
{
    
    if (palindromeUtility(&head, head) )
        cout << "Plaindrome!!";
    
    else
        cout << "Not a Plaindrome!";
}

bool palindromeUtility(struct node** left, struct node* right)
{
    if (right == NULL)
    {
        return true;
    }
    
    if ( palindromeUtility(left, right->next) && (*left)->data == right->data)
    {
        *left = (*left)->next;
        return  true;
    }
    
    
    return false;
}













