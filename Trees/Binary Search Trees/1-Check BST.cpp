//
//  main.c
//  Random C program
//
//  Created by Daman Saroa on 08/06/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

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

bool checkBST(struct node* root)
{
    if (!root)
        return true;
    
    if (root->left && root->left->data > root->data)
        return false;
    
    if (root->right && root->right->data < root->data)
        return false;
    
    return (checkBST(root->left) && checkBST(root->right));
}




int main()
{
    struct node *root = newNode(4);
    root->left        = newNode(2);
    root->right       = newNode(5);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);
    
    if(checkBST(root))
        printf("Is BST");
    else
        printf("Not a BST");
    
    
    return 0;
}
















