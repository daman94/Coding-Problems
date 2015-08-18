//
//  main.cpp
//  Random C++ program
//
//  Created by Daman Saroa on 01/09/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include<iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};


struct list{
    node* head;
    node* tail;
};

struct node* newNode(int data)
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

list treeToDLL(node* root)
{
    list p;
    p.head = NULL;
    p.tail = NULL;
    
    if (root)
    {
        list l=p, r=p;
        l = treeToDLL(root->left);
        r = treeToDLL(root->right);
        
        root->right = r.head;
        root->left = l.tail;
        
        if (l.tail)
            l.tail->right = root;
        
        if (r.head)
            r.head->left = root;
        
        p.head = l.head;
        
        if (!l.head) {
            p.head = root;
        }
        
        p.tail = r.tail;
        
        if (!r.tail)
        {
            p.tail = root;
        }
        
        p.tail->right = p.head;
        p.head->left = p.tail;
        
    }
    
    return p;
}


int main ()
{
    struct node *root = newNode(1);
    
    root->left = newNode(2);
    root->right = newNode(3);
    
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    
    
    list dll = treeToDLL(root);
    
    node* newList = dll.head;
    
    while (newList != dll.tail)
    {
        cout << newList->data<<" ";
        newList = newList->right;
    }
    cout << newList->data;
    
    
    cout<<endl;
    return 0;
}

