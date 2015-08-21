//
//  main.cpp
//  Random C++ program
//
//  Created by Daman Saroa on 16/08/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include<iostream>
#include <queue>
using namespace std;

struct node{
    int data;
    node** children;
    int childCount;
};

class GenericTree
{
    node* root;
    
public:
    GenericTree()
    {
        root = (node*)malloc(sizeof(node));
        
        queue<node*> Q;
        
        cout<<"Enter data for head: ";
        cin>>root->data;
        
        Q.push(root);
        
        while (!Q.empty())
        {
            node* temp = Q.front();
            Q.pop();
            
            cout<<"Enter child count for root: "<<temp->data << " : ";
            cin >> temp->childCount;
            
            temp->children = (node**)malloc(sizeof(node*)*temp->childCount);
            
            for (int i=0; i<temp->childCount; i++)
            {
                temp->children[i] = (node*)malloc(sizeof(node));
                cout << "Enter data for child of "<<temp->data << " : ";
                cin >> temp->children[i]->data;
                
                Q.push(temp->children[i]);
            }
            
        }
        
    }
    
    void PrintTree()
    {
        queue<node*> Q;
        Q.push(root);
        
        cout << root->data << " ";
        
        while (!Q.empty())
        {
            node* temp = Q.front();
            Q.pop();
            
            
            int count = temp->childCount;
            
            for(int i=0;i<count;i++)
            {
                cout << temp->children[i]->data << " ";
                Q.push(temp->children[i]);
            }
        }
    }
    
};

int main()
{
    GenericTree tree;
    tree.PrintTree();
    
    return 0;
}