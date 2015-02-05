//
//  main.cpp
//  Binary Search Trees
//
//  Created by Daman Saroa on 31/12/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* insert(node* node, int data);
void printLevelOrder(struct node* root);
void printInorder(struct node* root);
struct node* searchBST(node* root, int data);
node* removeFromBST(node* root, int data);
struct node* minValueNode(struct node* root);
int nextLargeValue(struct node* root , int data);
int minValue(struct node* root);
//bool checkBSTMethod1(struct node* root);
bool checkBST(struct node* root);
bool checkBSTUtil(struct node* root, int min, int max);
void printElementsInRange(struct node* root, int k1, int k2);

int main()
{
    struct node* root = NULL;
    
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 10);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 14);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 13);

    printInorder(root);
    cout << endl;

    printElementsInRange(root, 6, 12);
    cout << endl;

    
    return 0;
}

struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

node* insert(node* node, int data)
{
    if (node == NULL)
    {
        return (newNode(data));
    }
    else
    {
        if (data < node->data)
        {
            node->left = insert(node->left, data);
        }
        else if (data > node->data)
        {
            node->right = insert(node->right, data);
        }
        
        return node;
    }
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

void printInorder(struct node* root)
{
    if (root == NULL)
    {
        return;
    }
    
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
    
}

struct node* searchBST(node* root, int data)
{
    if (root == NULL)
    {
        cout << "NOt Found" << endl;
        return NULL;
    }
    if (data == root->data)
    {
        return root;
    }
    
    else if (data < root->data)
    {
        return searchBST(root->left, data);
    }
    
    else
    {
        return searchBST(root->right, data);
    }
}

node* removeFromBST(node* root, int data)
{
    if (root == NULL)
        return NULL;
    
    else if (data < root->data)
    {
        root->left = removeFromBST(root->left, data);
    }
    
    else if (data > root->data)
    {
        root->right = removeFromBST(root->right, data);
    }
    
    else
    {
        //Node with no child
        
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        //only one child
        
        if (root->right == NULL)
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        
        if (root->left == NULL)
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        
        // two children
        //replace with max of left or min of right
        
        else
        {
            struct node* temp = minValueNode(root->right);
            
            root->data = temp->data;
            
            root->right = removeFromBST(root->right, temp->data);
            
        }
        
    }
    
    return root;
}

struct node* minValueNode(struct node* root)
{
    struct node* temp = root;
    
    if (root->data < temp->data)
    {
        temp = root;
        root = root->left;
    }
    
    return temp;
}

int nextLargeValue(struct node* root , int data)
{
    // To find the inorder successor
    
    struct node* node = searchBST(root, data);
    
    if (node->right != NULL)
    {
        return minValue(node->right);
    }
    
    else
    {
        struct node* succ = NULL;
        
        while (root != node)
        {
            if (root->data > node->data)
            {
                succ = root;
                root = root->left;
            }
            
            else
            {
                root = root->right;
            }
        }
        
        if (succ == NULL)
        {
            return -1;
        }
        else
            
        return succ->data;
    }
    
    return 0;    
}

int minValue(struct node* root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    
    return root->data;
    
}

/*
bool checkBSTMethod1(struct node* root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL) )
    {
        return true;
    }
    
    else if ( root->left == NULL)
    {
        if (root->data < root->right->data)
        {
            return true;
        }
        else
            return false;
    }
    
    else if (root->right == NULL)
    {
        if (root->data > root->left->data)
        {
            return true;
        }
        else
            return false;
    }
    
    if (checkBST(root->left) && checkBST(root->right) && root->data > root->left->data && root->data < root->right->data)
    {
        return true;
    }
    
    else
        return false;
}
*/

bool checkBST(struct node* root)
{
    return checkBSTUtil(root, INT_MIN, INT_MAX);
    
}

bool checkBSTUtil(struct node* root, int min, int max)
{
    if (root ==  NULL)
    {
        return true;
    }
    
    else if (root->data < min || root->data > max)
    {
        return false;
    }
    
    return ( checkBSTUtil(root->left, min, root->data-1) &&
            checkBSTUtil(root->right, root->data+1, max) );
}

void printElementsInRange(struct node* root, int k1, int k2)
{
    if (root == NULL)
    {
        return;
    }
    
    if (root->data >= k1 && root->data <= k2 )
    {
        printElementsInRange(root->left, k1, k2);

        cout << root->data << " ";

        printElementsInRange(root->right, k1, k2);

    }
    
    else if (root->data < k1)
    {
        printElementsInRange(root->right, k1, k2);
    }
    
    else if (root->data > k2)
    {
        printElementsInRange(root->left, k1, k2);
    }
}






































