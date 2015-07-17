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

struct BTNode* DeepestNode(struct BTNode* root)
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
                break;
            else
            {
                q.push(NULL);
            }
        }
        else
        {
            temp = root;
            if (root->left)
                q.push(root->left);
            
            if (root->right)
                q.push(root->right);
        }
    }
    return temp;
}

struct BTNode* SearchNode(struct BTNode* root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    
    if (root->data == data) {
        return root;
    }
    
    if (SearchNode(root->left, data))
    {
        return SearchNode(root->left, data);
    }
    
    return SearchNode(root->right, data);
}

void DeleteNode(struct BTNode* root, int data)
{
    struct BTNode* searchedNode = SearchNode(root, data);
    
    struct BTNode* deepestNode = DeepestNode(root);
    
    searchedNode->data = deepestNode->data;
    
    
    free(deepestNode);
    
    
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
    
    
    DeleteNode(root, 4);
    
    
    LevelOrder(root);
    
    // DeleteTree(root);
    
    return 0;
}








































