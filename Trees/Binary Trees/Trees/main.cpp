//
//  main.cpp
//  Trees
//
//  Created by Daman Saroa on 26/12/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data);
void printPreOrder(struct node* root);
void printInOrder(struct node* root);
void printPostOrder(struct node* root);
void printLevelOrder(struct node* root);
void printLevelOrderIterative(struct node* root);
int size(struct node* root);
bool identicalTrees(struct node* root1, struct node* root2);
int maxDepth(struct node* root);
void deleteTree(struct node* root);
void createMirror(struct node* root);
void printPaths(struct node* root , int path[], int pathlen);
int getLeafCount(struct node* root);
void printSpiralRecursive(struct node* root);
void printGivenLevel (struct node* root , int level , int itr);
void printSpiralIterative(struct node* root);
bool isSumProperty(struct node* root);
void convertTree(struct node* root);
bool checkIdenticalTrees(struct node* root1, struct node* root2);
int firstLeafLevel(struct node* root , int level);
bool checkLeavesLevel(struct node* root , int level , int firstLeaf_level);
void printVertically(struct node* root);
void findMinMax(node* node, int* min, int* max, int hd);
void printVerticalLine(node* node, int line, int hd);


int main ()
{
    struct node *root = newNode(1);
    
    root->left = newNode(2);
    root->right = newNode(3);
    
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    
        
    printLevelOrder(root);
    cout<< endl;
    
    printVertically(root);
    
    cout<<endl;
    return 0;
}

struct node* newNode(int data)
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}

void printPreOrder(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    
    cout << root->data << " ";
    
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printInOrder(struct node* root)
{
    if(root == NULL)
    {
        return;
    }
    
    printInOrder(root->left);
    
    cout << root->data << " ";
    
    printInOrder(root->right);
}

void printPostOrder(struct node* root)
{
    if (root == NULL)
    {
        return;
    }
    
    printPostOrder(root->left);
    printPostOrder(root->right);
    
    cout << root->data << " ";
}

void printLevelOrderIterative(struct node* root)
{
    int s = size(root);
    
    for (int i=0; i<s ; i++)
    {
        printGivenLevel(root, i, true);
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

int size(struct node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    
    return (size(root->left) + size(root->right) + 1);
    
}

bool identicalTrees(struct node* root1, struct node* root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    
    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    
    else if ( (root1->data == root2->data) && identicalTrees(root1->left, root2->left) && identicalTrees(root1->right, root2->right) )
    {
        return true;
    }
    
    return false;
}

int maxDepth(struct node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    
    if ( maxDepth(root->left) >= maxDepth(root->right) )
    {
        return (maxDepth(root->left) + 1 );
    }
    else
        return (maxDepth(root->right) + 1);
}

void deleteTree(struct node* root)
{
    if (root == NULL)
    {
        return;
    }
    
    deleteTree(root->left);
    deleteTree(root->right);
    
    cout<<"Deleting node" << root->data << " ";
    
    free(root);
}

void createMirror(struct node* root)
{
    if (root == NULL)
    {
        return;
    }
    
    createMirror(root->left);
    createMirror(root->right);
    
    struct node* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void printPaths(struct node* root , int path[], int pathlen)
{
    if (root == NULL)
    {
        return;
    }

    path[pathlen] = root->data;
    
    if (root->left == NULL && root->right == NULL)
    {
        for (int i=0; i <= pathlen; i++)
        {
            cout << path[i] << " ";
        }
        
        cout<<endl;
        
        return;
    }
    
    
    printPaths(root->left, path, pathlen+1);
    printPaths(root->right, path, pathlen+1);

}

int getLeafCount(struct node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    
    else
        return ( getLeafCount(root->left) + getLeafCount(root->right) );
}

void printSpiralRecursive(struct node* root)
{
    int h = size(root);
    
    int i;
    
    bool itr = true;
    //itr = false means traversal from left to right
    
    for (i=0; i<h; i++)
    {
        printGivenLevel(root, i, itr);
        
        itr = !itr;
    }
}

void printGivenLevel (struct node* root , int level , int itr)
{
    if (root == NULL)
    {
        return;
    }
    
    if (level == 1)
    {
        cout << root->data << " ";
    }
    
    else if (level > 1)
    {
        if (itr == true)
        {
            printGivenLevel(root->left, level-1, itr);
            printGivenLevel(root->right, level-1, itr);
        }
        
        else if (itr == false)
        {
            printGivenLevel(root->right, level-1, itr);
            printGivenLevel(root->left, level-1, itr);
        }
    }
    
    return;
}

void printSpiralIterative(struct node* root)
{
    stack<struct node*> s1;
    stack<struct node*> s2;
    
    if (root == NULL)
    {
        return;
    }
    
    s1.push(root);
    
    while ( !s1.empty() )
    {
        struct node* temp = s1.top();
        cout << temp->data;
        s1.pop();
        
        s2.push(temp->right);
        s2.push(temp->left);
        
    }
    
    while ( !s2.empty() )
    {
        struct node* temp2 = s2.top();
        cout << temp2->data;
        
        s2.pop();
        
        s1.push(temp2->left);
        s1.push(temp2->right);
    }

}

bool isSumProperty(struct node* root)
{
    if (root == NULL)
    {
        return true;
    }
    
    else if (root->left && root->right)
    {
        if (root->data == root->left->data + root->right->data)
        {
            return ( isSumProperty(root->left) && isSumProperty(root->right) );
        }
        
        else
            return false;
    }
    
    else if (root->left)
    {
        if (root->data == root->left->data)
        {
            return (isSumProperty(root->left));
        }
        else
            return false;
    }
    
    else if (root->right)
    {
        if (root->data == root->right->data)
        {
            return (isSumProperty(root->right));
        }
        else
            return false;
    }
    
    return true;
}

void convertTree(struct node* root)
{
    
}

bool checkIdenticalTrees(struct node* root1, struct node* root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    
    else if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    
    else if (root1->data == root2->data)
    {
        return ( checkIdenticalTrees(root1->left, root2->left) && checkIdenticalTrees(root1->right, root2->right) );
    }
    
    else
    return false;
}

int firstLeafLevel(struct node* root , int level)
{
    if (root->left == NULL && root->right == NULL)
    {
        return level;
    }
    
    else
    {
        return (firstLeafLevel(root->left , level + 1 ));
    }

}

bool checkLeavesLevel(struct node* root , int level , int firstLeaf_level)
{
    if (root == NULL)
    {
        return true;
    }
    
    else if (root->left == NULL && root->right == NULL)
    {
        //Leaf node
        
        if (level == firstLeaf_level)
        {
            return true;
        }
        else
            return false;
    }
    
    return (checkLeavesLevel(root->left, level+1, firstLeaf_level) && checkLeavesLevel(root->right, level+1, firstLeaf_level));
}

void printVertically(struct node* root)
{
    int min = 0;
    int max = 0;
    
    findMinMax(root, &min, &max, 0);
    
    for (int line = min; line <= max; line++ )
    {
        printVerticalLine(root, line, 0);
        cout << endl;
    }
    
}

void findMinMax(node* node, int* min, int* max, int hd)
{
    if (node == NULL)
    {
        return;
    }
    
    if (hd < *min)
    {
        *min = hd;
    }
    
    else if (hd > *max)
    {
        *max = hd;
    }
    
    findMinMax(node->left, min, max, hd-1);
    findMinMax(node->right, min, max, hd+1);
}

void printVerticalLine(node* node, int line, int hd)
{
    if (node == NULL)
    {
        return;
    }
    
    if (line == hd)
    {
        cout << node->data << " ";
    }
    
    printVerticalLine(node->left, line, hd-1);
    printVerticalLine(node->right, line, hd+1);
    
}



















