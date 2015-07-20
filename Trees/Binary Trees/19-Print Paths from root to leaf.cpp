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

void PrintPaths(struct BTNode* root, int *arr, int i)
{
    if (!root) return;
    
    if (root->left == NULL && root->right == NULL)
    {
        arr[i] = root->data;
        for (int j=0; j<=i; j++)
        {
            cout << arr[j] << " ";
        }
        cout << endl;
        return;
    }
    
    arr[i++] = root->data;
    
    PrintPaths(root->left, arr, i);
    PrintPaths(root->right, arr, i);
    return;
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
    root->right->right->left = newNode(9);
    
    
    int arr[10];
    
    PrintPaths(root, arr, 0);
    
    
    DeleteTree(root);
    
    return 0;
}















