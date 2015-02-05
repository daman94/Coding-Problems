//
//  main.cpp
//  Tree with Classes
//
//  Created by Daman Saroa on 29/12/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <hashtable>
using namespace std;

class Node {
    int data;
    Node * left;
    Node * right;
    
    public:
    
    Node(const int element)
    {
        data = element;
        left = NULL;
        right = NULL;
    }
    
    void setData(const int & element)
    {
        data = element;
    }
    
    void setLeft( Node * const l)
    {
        left = l;
    }
    
    void setRight(Node * const r)
    {
        right = r;
    }
    
    int getData() const
    {
        return data;
    }
    
    Node* getLeft() const
    {
        return  left;
        
    }
    
    Node* getRight() const
    {
        return right;
    }
    
    friend void printData(Node A);
    
};

class tree {
    Node* root;
    static void printInorder(Node* root)
    {
        if (root == NULL)
        {
            return;
        }
        
        printInorder(root->getLeft());
        cout << root->getData() <<endl;
        printInorder(root->getRight());
        
        return;
    }
public:
    void inorderPrint() const
    {
        tree::printInorder(root);
    }
    
    
    // cin >> tree ???
    
    
    operator>>(istream &in)
    {
        root = NULL;
        int data;
        root = new Node
    }
};


void printData(Node A)
{
    cout << A.data  << endl;
}

int main()
{
    Node a(10), b(10), c(10);
    a.setLeft(&b);
    a.setRight(&c);
    
    Node * p = a.getLeft();
    p = &c;
    
    const Node d(20);
    //d.setData(70);
   
    //cout<<d.getData();
    
    
    printData(a);
    
    return 0;
}




























