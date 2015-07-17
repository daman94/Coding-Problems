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
    struct BTNode* newNode = (struct BTNode*) malloc(sizeof(struct BTNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

void DeleteTree(struct BTNode* &root)
{
    if(root == NULL)
        return;
    
    else
    {
        DeleteTree(root->left);
        DeleteTree(root->right);
        free(root);
        root = NULL;
    }
}

int DeepestLeftLeaf(struct BTNode* root)
{
    queue<struct BTNode*> q;
    
    struct BTNode* temp = root;
    
    q.push(root);
    q.push(NULL);
    
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        
        if (root == NULL)
        {
            if (q.empty())
                return temp->data ;
            else
            {
                q.push(NULL);
                temp = q.front();
            }
        }
        
        else
        {
            if (root->left)
                q.push(root->left);
            
            if (root->right)
                q.push(root->right);
        }
    }
    
    return temp->data;
}


int main()
{
    struct BTNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->right->right->right = newNode(10);
    
    cout << DeepestLeftLeaf(root);
    
    
    DeleteTree(root);
    
    return 0;
}







































