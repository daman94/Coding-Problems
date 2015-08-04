//
//  main.c
//  Random C program
//
//  Created by Daman Saroa on 08/06/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//

#include <iostream>
using namespace std;

struct prateek {
    struct node* head;
    struct node* tail;
};

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* root = (struct node*)malloc(sizeof(struct node));
    
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    
    return root;
}

struct prateek BSTtoDLL(struct node* root)
{
    struct prateek p;
    p.head = NULL;
    p.tail = NULL;
    
    if(!root->left && !root->right)
    {
        p.head = root;
        p.tail = root;
        return p;
    }
    
    if(root->left && !root->right)
    {
        p = BSTtoDLL(root->left);
        p.tail->right = root;
        root->left = p.tail;
        p.tail = root;
        return p;
    }
    
    if(root->right && !root->left)
    {
        p = BSTtoDLL(root->right);
        root->right = p.head;
        p.head->left = root;
        p.head = root;
        return p;
    }
    
    else
    {
        struct prateek p1;
        p = BSTtoDLL(root->left);
        p1 = BSTtoDLL(root->right);
        
        p.tail->right = root;
        root->right = p1.head;
        root->left = p.tail;
        p1.head->left = root;
        
        struct prateek p2;
        p2.head = p.head;
        p2.tail = p1.tail;
        return p2;
    }
}

void printLL(struct prateek p)
{
    struct node* temp = p.head;
    
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
}

int main()
{
    struct node *root = newNode(6);
    root->left        = newNode(2);
    root->right       = newNode(8);
    root->left->left  = newNode(1);
    root->left->right = newNode(9);
    
    struct prateek p = BSTtoDLL(root);
    
    printLL(p);
    
    
    return 0;
}
















