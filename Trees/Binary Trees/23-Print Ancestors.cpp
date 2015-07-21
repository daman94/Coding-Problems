//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <queue>
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

void PrintPreOrder(struct BTNode* root)
{
    if (!root) {
        return;
    }
    
    cout << root->data << " ";
    PrintPreOrder(root->left);
    PrintPreOrder(root->right);
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

bool PrintAncestors(struct BTNode* root, struct BTNode* node)
{
    if (!root)
    {
        return false;
    }
    
    if ( root->left == node || root->right == node || PrintAncestors(root->left, node) || PrintAncestors(root->right, node) )
    {
        cout << root->data << " ";
        return true;
    }
    return false;
}

struct BTNode* Search(struct BTNode* root, int data)
{
    if (!root) {
        return NULL;
    }
    
    if (root->data == data) {
        return root;
    }
    
    if (Search(root->left, data))
    {
        return Search(root->left, data);
    }
    
    else
        return Search(root->right, data);
    
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
    
    
    struct BTNode* node = Search(root,5);
    
    PrintAncestors(root, node);
    
    
    DeleteTree(root);
    return 0;
}















