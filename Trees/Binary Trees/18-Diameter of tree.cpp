//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

struct BTNode {
    int data;
    struct BTNode* left;
    struct BTNode* right;
};

struct BTNode* newNode(int data)
{
    struct BTNode* newnode = new struct BTNode;
    
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    
    return newnode;
}

void DeleteTree(struct BTNode* root)
{
    if (root)
    {
        DeleteTree(root->left);
        DeleteTree(root->right);
        free(root);
    }
    else
        return;
}

int FindHeight(struct BTNode* root)
{
    if (!root)
        return 0;
    
    int l,r;
    l = FindHeight(root->left);
    r = FindHeight(root->right);
    
    return (max(l,r) + 1);
}

int FindDiameter(struct BTNode* root, int* height)
{
    int lh=0, rh=0, ld=0, rd=0;
    
    if (!root)
    {
        *height = 0;
        return 0;
    }
    
    ld = FindDiameter(root->left, &lh);
    rd = FindDiameter(root->right, &rh);
    
    *height = max(lh,rh) + 1;
    
    return max( lh+rh+1, max(ld, rd) );
}

int main()
{
    struct BTNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->right->left = newNode(9);
    
    int height=0;
    
    cout << FindDiameter(root, &height);
    
    
    DeleteTree(root);
    
    return 0;
}















