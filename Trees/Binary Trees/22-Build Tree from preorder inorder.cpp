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

struct BTNode* BuildBinaryTree(int* preorder, int* inorder, int inStart, int inEnd)
{
    static int preIndex = 0;
    if (inStart > inEnd)
    {
        return NULL;
    }
    
    int item = preorder[preIndex++];
    
    struct BTNode* newnode = newNode(item);
    
    if (inStart == inEnd) {
        return newnode;
    }
    
    int inIndex = inStart;
    while ( inIndex<=inEnd && item != inorder[inIndex])
    {
        inIndex++;
    }
    
    newnode->left = BuildBinaryTree(preorder, inorder, inStart, inIndex-1);
    newnode->right = BuildBinaryTree(preorder, inorder, inIndex+1, inEnd);
    
    return newnode;
}


int main()
{
    struct BTNode *root = NULL;
    
    int preOrder[] = {1,2,4,5,3,6};
    int inOrder[] = {4,2,5,1,6,3};
    
    root = BuildBinaryTree(preOrder, inOrder, 0,5);
    
    
    PrintPreOrder(root);
    
    
    DeleteTree(root);
    return 0;
}















