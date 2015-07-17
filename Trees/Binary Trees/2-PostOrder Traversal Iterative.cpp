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
    struct BTNode* newNode = (struct BTNode*) malloc(sizeof(struct BTNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

void PostOrderNonRecursive(struct BTNode* root)
{
    stack<struct BTNode*> s;
    
    while (1)
    {
        if (root != NULL)
        {
            s.push(root);
            root = root->left;
        }
        
        else
        {
            if (s.top()->right == NULL)
            {
                root = s.top();
                s.pop();
                cout << root->data;
                
                while (!s.empty() && root == s.top()->right)
                {
                    root = s.top();
                    s.pop();
                    cout << root->data;
                }
            }
            
            if (!s.empty())
            {
                root = s.top()->right;
            }
            
            else
            {
                return;
            }
        }
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
    
    PostOrderNonRecursive(root);
    
    
    
    return 0;
}








































