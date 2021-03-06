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

int size(struct BTNode* root)
{
    if (!root)
        return 0;
    
    return (size(root->left) + size(root->right) + 1);
}

void LevelOrder(struct BTNode* root)
{
    queue<struct BTNode*> q;
    
    q.push(root);
    
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        
        cout << root->data << " ";
        
        if (root->left)
            q.push(root->left);
        if (root->right)
            q.push(root->right);
        
    }
    
    cout << endl;
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
    
    LevelOrder(root);
    
    cout << size(root);
    
    return 0;
}








































