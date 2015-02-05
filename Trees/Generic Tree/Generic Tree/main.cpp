//
//  main.cpp
//  Generic Tree
//
//  Created by Daman Saroa on 30/12/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data;
    node** children;
    int childCount;
};

struct box
{
    int sum;
    node* maxNode;
};

node* BuildTree();
void BuildTreeRecursively(node** rootRef);
void levelOrderPrint(node* root);
void preOrderPrint(node* root);
void postOrderPrint(node* root);
box maxSum(node* node);
int findMax(int arr[]);



int main()
{
    node* root = NULL;
    
    root = BuildTree();
    
    levelOrderPrint(root);
    
    cout << endl;
    
    struct box obj;
    obj = maxSum(root);
    
    cout << obj.sum << " " << obj.maxNode->data << endl;
    
    
    return 0;
}

node* BuildTree()
{
    node* root = new node;
    cout << "Enter data for root: ";
    cin >> root->data;
    
    queue < node* > q;
    q.push(root);
    
    while (!q.empty() )
    {
        node* temp = q.front();
        q.pop();
        
        cout << "enter no of children of " << temp->data <<": ";
        cin >> temp->childCount;
        
        temp->children = new node*[temp->childCount];
        
        for (int i=0; i< temp->childCount ; i++)
        {
            temp->children[i] = new node;
            
            cout << "Enter child data ";
            cin >> temp->children[i]->data;
            
            q.push(temp->children[i]);
        }
    }
    
    return root;
}

void BuildTreeRecursively(node** rootRef)
{
    if(*rootRef == NULL)
    {
        *rootRef = new node;
        
        cout << "enter node's data: ";
        cin >> (*rootRef)->data;
        
        cout << "enter no of children: ";
        cin >> (*rootRef)->childCount;
        
        if ((*rootRef)->childCount == 0)
        {
            return;
        }
        
        (*rootRef)->children = new node*[(*rootRef)->childCount];
        
        
        for (int i=0; i<(*rootRef)->childCount; i++)
        {
            (*rootRef)->children[i] = NULL;

            BuildTreeRecursively( &(*rootRef)->children[i]);
        }
    }
}

void levelOrderPrint(node* root)
{
    if (root == NULL)
    {
        return;
    }
    
    else
    {
        queue < node* > q;
        q.push(root);
        
        while (!q.empty() )
        {
            node * temp = q.front();
            cout << temp->data;
            
            for (int i = 0; i < temp->childCount; i++)
            {
                q.push(temp->children[i]);
            }
            
            q.pop();

        }
    }
    
}

void preOrderPrint(node* root)
{
    if (root == NULL)
    {
        return;
    }
    
    else
    {
        cout << root->data << " ";
        
        for (int i=0; i < root->childCount; i++)
        {
            preOrderPrint(root->children[i]);
        }
    }
    
}

void postOrderPrint(node* root)
{
    if (root == NULL)
    {
        return;
    }
    
    else
    {
        for (int i=0; i < root->childCount; i++)
        {
            postOrderPrint(root->children[i]);
        }
        
        cout << root->data << " ";
        
    }
}

box maxSum(node* node)
{
    struct box object;
    
    if (node == NULL)
    {
        object.sum = 0;
        object.maxNode = NULL;
        
        return object;
    }
    
    
    else
    {
        object.sum = node->data;
        object.maxNode = node;
        
        for (int i=0; i < node->childCount; i++)
        {
            object.sum += node->children[i]->data;
        }
        
        struct box object2;
        
        for (int j=0; j < node->childCount; j++)
        {
            object2 = maxSum(node->children[j]);
            
            if (object2.sum > object.sum)
            {
                object.sum = object2.sum;
                object.maxNode = object2.maxNode;
            }
        }
        
        return object;
        
    }
    
    
}

int findMax(int arr[])
{
    int max = -10000 , k=0;
    
    while (arr[k] != -1000)
    {
        if (arr[k] > max)
        {
            max = arr[k];
        }
        
        k++;
    }
    
    return max;
}































