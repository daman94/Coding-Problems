//
//  main.cpp
//  Random C++ program
//
//  Created by Daman Saroa on 16/08/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

struct node
{
    int data;
    node* next;
    node* rand;
};

node* NewNode(int data)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->rand = NULL;
    
    return newnode;
}

void printList(node* head)
{
    node* current = head;
    while (current) {
        cout << current->data << " -> ";
        current = current->next;
    }
    
    cout <<  endl;
}

node* cloneList(node* head)
{
    node* current = head;
    node* prev = NULL;
    
    map<node*, node*> m;
    
    while (current) {
        m[current] = current->next;
        current = current->next;
    }
    
    current = head;
    node* newHead = NewNode(current->data);
    
    prev = newHead;
    current = current->next;
    
    while (current) {
        prev->next = NewNode(current->data);
        prev = prev->next;
        current = current->next;
    }
    
    current = head;
    node* next;
    node* newCurrent = newHead;
    
    while (current) {
        next = current->next;
        current->next = newCurrent;
        newCurrent = newCurrent->next;
        current = next;
    }
    
    current = head;
    while (current) {
        current->next->rand = current->rand->next;
        current = m[current];
    }
    
    current = head;
    while (current) {
        current->next = m[current];
        current = current->next;
    }
    
    return newHead;
}

int main()
{
    node* head = NewNode(1);
    head->next = NewNode(2);
    head->next->next = NewNode(3);
    head->next->next->next = NewNode(4);
    head->next->next->next->next = NewNode(5);
    
    head->rand = head->next->next;
    head->next->rand = head;
    head->next->next->rand = head->next->next->next->next;
    head->next->next->next->rand = head->next->next;
    head->next->next->next->next->rand = head->next;
    
    //printList(head);
    
    printList(cloneList(head));
    
    return 0;
}


























