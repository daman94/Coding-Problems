//
//  main.cpp
//  Random C++ program
//
//  Created by Daman Saroa on 16/08/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
using namespace std;

template<typename T>

class node{
public:
    T data;
    node<T>* next;
};

template<typename T>

class list{
    node<T>* head;
    
public:
    list()
    {
        head = NULL;
    }
    
    node<T>* tail()
    {
        node<T>* current = head;
        while (current->next) {
            current  =current->next;
        }
        return current;
    }
    
    void push_back(T data)
    {
        node<T>* newnode = (node<T>*) malloc(sizeof(node<T>));
        newnode->data = data;
        newnode->next = NULL;
        
        if (head == NULL) {
            head = newnode;
        }
        else
            tail()->next = newnode;
    }
    
    void pop_back()
    {
        node<T>* prev = head;
        
        while (prev->next->next) {
            prev = prev->next;
        }
        
        node<T>* tail = prev->next;
        free(tail);
        prev->next = NULL;
    }
    
    void push_front(T data)
    {
        node<T>* newnode = (node<T>*)malloc(sizeof(node<T>));
        newnode->data = data;
        newnode->next=  head;
        head = newnode;
    }
    
    void pop_front()
    {
        node<T>* current = head;
        head=  head->next;
        free(current);
    }
    
    void reverse()
    {
        node<T>* prev = NULL;
        node<T>* current = head;
        node<T>* next = NULL;
        
        while (current) {
            next = current->next;
            current->next  = prev;
            prev=  current;
            current=  next;
        }
        
        head = prev;
    }
    
    void print()
    {
        node<T>* current = head;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
    }
    
    ~list()
    {
        node<T>* prev = head;
        node<T>* current;
        
        while (prev) {
            current = prev->next;
            free(prev);
            prev = current;
        }
        head = NULL;
    }
};

int main()
{
    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.pop_back();
    l.push_front(0);
    l.pop_front();
    l.reverse();
    
    l.print();
    
    cout<<endl;
    
    list<char> l1;
    l1.push_front('a');
    l1.push_back('b');
    l1.push_back('c');
    l1.push_back('d');
    l1.pop_front();
    
    l1.print();
    
    return 0;
}















