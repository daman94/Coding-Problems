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

void FindPathWithSum(struct BTNode* root, int sum, int *arr, int i)
{
    if (!root)
    {
        return;
    }
    
    arr[i++] = root->data;
    sum = sum - root->data;
    
    if (sum == 0)
    {
        cout << "path found: ";
        
        for(int j=0;j<i;j++)
        {
            cout << arr[j];
        }
        
        cout << endl;
    }
    
    FindPathWithSum(root->left, sum, arr, i);
    FindPathWithSum(root->right, sum, arr, i);
    return;
}



int main()
{
    struct BTNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(3);
    root->right->right = newNode(7);
    root->right->right->left = newNode(9);
    
    int arr[10];
    
    FindPathWithSum(root, 7, arr, 0);
    
    
    
    
    DeleteTree(root);
    
    return 0;
}















