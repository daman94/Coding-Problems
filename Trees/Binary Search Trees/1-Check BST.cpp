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

int FindMax(struct node* root)
{
    if (!root)
        return -1;
    
    int max = root->data;
    
    int l = FindMax(root->left);
    int r = FindMax(root->right);
    
    if (l>max)
        max = l;
    if (r>max)
        max = r;
    
    return max;
    
}

int FindMin(struct node* root)
{
    if (!root)
        return -1;
    
    int min = root->data;
    
    int l = FindMin(root->left);
    int r = FindMin(root->right);
    
    if (l<min)
        min = l;
    if (r<min)
        min = r;
    
    return min;
    
}


bool checkBST(struct node* root)
{
    if (!root)
        return true;
    
    if (root->left && FindMax(root->left) > root->data)
        return false;
    
    if (root->right && FindMin(root->right) < root->data)
        return false;
    
    if (!checkBST(root->left) || !checkBST(root->right))
        return false;
    
    return true;
}




int main()
{
    struct node *root = newNode(6);
    root->left        = newNode(2);
    root->right       = newNode(8);
    root->left->left  = newNode(1);
    root->left->right = newNode(9);
    
    if(checkBST(root))
        printf("Is BST");
    else
        printf("Not a BST");
    
    
    return 0;
}
















