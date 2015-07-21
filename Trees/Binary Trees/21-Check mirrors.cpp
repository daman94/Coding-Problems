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

void Mirror(struct BTNode* &root)
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

bool CheckMirror(struct BTNode* root1, struct BTNode* root2)
{
    if (!root1 && !root2)
    {
        return true;
    }
    
    else if (!root1 || !root2)
    {
        return false;
    }
    
    else if (root1->data == root2->data)
    {
        return ( CheckMirror(root1->left, root2->right) && CheckMirror(root1->right, root2->left) );
    }
    
    return false;
}

int main()
{
    struct BTNode *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    
    
    struct BTNode * root2 = newNode(1);
    root2->left = newNode(3);
    root2->right  =newNode(2);
    root2->right->left = newNode(5);
    root2->right->right = newNode(4);
    
    if (CheckMirror(root, root2)) {
        cout << "Trees are mirrors of each other..";
    }
    
    else
        cout << "Not mirror";
    
    DeleteTree(root);
    DeleteTree(root2);
    
    return 0;
}















