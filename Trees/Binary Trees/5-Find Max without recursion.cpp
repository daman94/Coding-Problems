//
//  5-Find Max without recursion.cpp
//  Random C++ program
//
//  Created by Daman Saroa on 17/07/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <stdio.h>
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

void findMax(struct BTNode* root)
{
    queue<struct BTNode*> q;
    int max = INT_MIN;
    q.push(root);
    
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        
        if (max < root->data)
            max = root->data;
        
        if (root->left)
            q.push(root->left);
        if (root->right)
            q.push(root->right);
        
    }
    
    cout << max;
}


int main()
{
    struct BTNode* root = newNode(131);
    root->left = newNode(2);
    root->right = newNode(13);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    
    
    findMax(root);
    
    return 0;
}








































