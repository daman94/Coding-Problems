//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stack>
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

void LevelOrderInReverse(struct BTNode* root)
{
    stack<struct BTNode*> s;
    queue<struct BTNode*> q;
    
    q.push(root);
    
    struct BTNode* temp = NULL;
    
    while (!q.empty())
    {
        root = q.front();
        s.push(root);
        q.pop();
        
        if (root->right) {
            q.push(root->right);
        }
        
        if (root->left) {
            q.push(root->left);
        }
    }
    
    while (!s.empty())
    {
        cout << s.top()->data << " ";
        s.pop();
    }
    
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
    
    LevelOrderInReverse(root);
    
    return 0;
}








































