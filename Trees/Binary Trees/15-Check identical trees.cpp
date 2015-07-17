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

bool checkIdentical(struct BTNode* root1, struct BTNode* root2)
{
    if (!root1 && !root2)
        return true;
    
    else if (!root1 && root2)
        return false;
    
    else if (root1 && !root2)
        return false;
    
    return ( (root1->data == root2->data) && (checkIdentical(root1->left, root2->left)) && (checkIdentical(root1->right, root2->right)) );
}

int main()
{
    struct BTNode *root1 = newNode(1);
    struct BTNode *root2 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left  = newNode(4);
    root1->left->right = newNode(5);
    
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(15);
    
    if( checkIdentical(root1, root2))
        printf("Both tree are identical.");
    else
        printf("Trees are not identical.");
    
    
    
    DeleteTree(root1);
    DeleteTree(root2);
    
    return 0;
}








































