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

void inOrder(struct BTNode* root)
{
    if (!root) {
        return;
    }
    
    inOrder(root->left);
    cout << root->data;
    inOrder(root->right);
}

void Mirror(struct BTNode* root)
{
    if (!root) return;
    
    if (root->left && root->right)
    {
        struct BTNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
    
    else if (root->left)
    {
        root->right = root->left;
        root->left = NULL;
    }
    
    else if (root->right)
    {
        root->left = root->right;
        root->right = NULL;
    }
    
    Mirror(root->left);
    Mirror(root->right);
    return;
}



int main()
{
    struct BTNode *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    
    
    printf("\n Inorder traversal of the constructed tree is \n");
    inOrder(root);
    cout << endl;
    
    
    Mirror(root);
    
    
    printf("\n Inorder traversal of the mirror tree is \n");
    inOrder(root);
    
    DeleteTree(root);
    
    return 0;
}















