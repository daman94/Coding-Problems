//
//  main.cpp
//  Create Binary Tree from Inorder and Preorder
//
//  Created by Daman Saroa on 28/12/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

struct node
{
    char data;
    struct node* left;
    struct node* right;
};

struct node* newNodeChar(char value);
void printLevelOrder(struct node* root);
void printLevelOrder(struct node* root);
struct node* buildTree(char pre[], char in[], int inStart , int inEnd, int preIndex);
int searchIndex(char in[] , int start , int end , int value );



int main ()
{
    char pre[] = "abdecf";
    char in[] = "dbeafc";
    
    struct node* root = NULL;
    
    root = buildTree(pre, in, 0, 5, 0);
    
    
    printLevelOrder(root);
    cout<< endl;
    
    
    cout<<endl;
    return 0;
}

struct node* newNodeChar(char value)
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
    
}

void printLevelOrder(struct node* root)
{
    queue<struct node*> myQueue;
    
    myQueue.push(root);
    
    while ( !myQueue.empty() )
    {
        struct node* node = myQueue.front();
        
        cout << node->data << " ";
        
        if (node->left != NULL)
        {
            myQueue.push(node->left);
        }
        
        if (node->right != NULL)
        {
            myQueue.push(node->right);
        }
        
        myQueue.pop();
    }
}


struct node* buildTree(char pre[], char in[], int inStart , int inEnd, int preIndex)
{
    if (inStart > inEnd)
    {
        return NULL;
    }
    
    char temp = pre[preIndex];
    preIndex++;
    
    cout<<temp<<endl;
    
    struct node* root = newNodeChar(temp);
    
    if (inStart == inEnd)
    {
        return root;
    }
    
    int inIndex = searchIndex(in, inStart, inEnd, root->data);
    
    cout<<inStart<<endl;
    
    root->left = buildTree(pre, in, inStart, inIndex-1 , preIndex);
    root->right = buildTree(pre, in, inIndex+1, inEnd, preIndex);
    
    return root;
}

int searchIndex(char in[] , int start , int end , int value )
{
    int k = start;
    while (in[k] != value && k <= end)
    {
        k++;
    }
    
    return k;
    
}


