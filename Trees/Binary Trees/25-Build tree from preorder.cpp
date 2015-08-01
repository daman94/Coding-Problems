//
//  main.c
//  Random C program
//
//  Created by Daman Saroa on 08/06/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

struct node {
    char data;
    struct node* left;
    struct node* right;
};

struct node* newNode(char data)
{
    struct node* root = (struct node*)malloc(sizeof(struct node));
    
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    
    return root;
}

struct node* BuildTree(char* a, int* i)
{
    if (a[*i] != '\0')
    {
        struct node* root = newNode(a[*i]);
        if (a[*i] == 'L')
        {
            (*i)++;
            return root;
        }
        (*i)++;
        root->left = BuildTree(a, i);
        root->right = BuildTree(a, i);
        
        return root;
    }
    
    return NULL;
}

void LevelOrderPrint(struct node* root)
{
    queue<struct node*> q;
    
    q.push(root);
    while (!q.empty())
    {
        struct node* temp = q.front();
        q.pop();
        if (temp->left) {
            q.push(temp->left);
        }
        
        if (temp->right) {
            q.push(temp->right);
        }
        
        cout << temp->data <<" ";
    }
    
}


int main()
{
    char* a = "IIILLILL";
    int index=0;
    
    struct node* root = BuildTree(a, &index);
    
    LevelOrderPrint(root);
    
    
    
    return 0;
}
















