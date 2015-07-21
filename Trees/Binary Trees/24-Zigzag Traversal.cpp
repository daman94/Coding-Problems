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

void ZigZagTraversal(struct BTNode* root)
{
    queue<struct BTNode*> q;
    stack<struct BTNode*> s;
    
    int flag = 0;
    
    q.push(root);
    q.push(NULL);
    
    struct BTNode* temp = q.front();
    
    while (!q.empty())
    {
        if (temp == NULL)
        {
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        
        else
        {
            if (flag == 0)
            {
                while (temp!=NULL)
                {
                    q.pop();
                    cout << temp->data << " ";
                    
                    if (temp->left)
                        q.push(temp->left);
                    
                    if (temp->right)
                        q.push(temp->right);
                    temp = q.front();
                }
                
                flag = 1;
            }
            
            else
            {
                while (temp!=NULL)
                {
                    q.pop();
                    
                    if (temp->left)
                        q.push(temp->left);
                    
                    if (temp->right)
                        q.push(temp->right);
                    
                    s.push(temp);
                    temp = q.front();
                }
                
                while (!s.empty())
                {
                    cout << s.top()->data << " ";
                    s.pop();
                }
                flag = 0;
            }
        }
        
        temp = q.front();
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
    
    ZigZagTraversal(root);
    
    
    DeleteTree(root);
    return 0;
}















