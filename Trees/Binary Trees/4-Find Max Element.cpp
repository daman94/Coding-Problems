//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
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

int max(int a, int b, int c)
{
    if (a>b && a>c)
        return a;
    
    else if (b>a && b>c)
        return b;
    else
        return c;
}

int FindMaxElement(struct BTNode* root)
{
    if(!root)
        return INT_MIN;
    
    int l,r;
    l = FindMaxElement(root->left);
    r = FindMaxElement(root->right);
    
    return max(root->data, l, r);
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
    
    cout << FindMaxElement(root);
    
    return 0;
}








































