//
//  main.c
//  Random C program
//
//  Created by Daman Saroa on 08/06/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//
#include <iostream>
#include <map>
using namespace std;

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

class queue{
    int maxCapacity;
    int currentCapacity;
    node* head;
    node* tail;
    
public:
    queue()
    {
        head = NULL;
        tail = NULL;
    }
    
    void setHead(node* temp)
    {
        head = temp;
    }
    
    void setTail(node* temp)
    {
        tail = temp;
    }
    
    void setCapacity(int n)
    {
        maxCapacity = n;
    }
    
    node* front()
    {
        return head;
    }
    
    node* rear()
    {
        return tail;
    }
    
    node* enqueue(int data)
    {
        if (currentCapacity == maxCapacity)
        {
            dequeue();
            return enqueue(data);
        }
        else{
            struct node* temp = (struct node*)malloc(sizeof(struct node));
            temp->data = data;
            temp->next = NULL;
            
            if (currentCapacity ==0) {
                //empty queue
                
                temp->prev=NULL;
                head = temp;
                tail = temp;
                currentCapacity++;
            }
            
            else {
                temp->prev = tail;
                tail->next = temp;
                tail = tail->next;
                currentCapacity++;
            }
            
            
            return temp;
        }
    }
    
    void dequeue()
    {
        if (currentCapacity == 0)
        {
            cout << "queue is empty";
        }
        
        else
        {
            struct node* temp = head;
            head->next->prev = NULL;
            head = head->next;
            free(temp);
            currentCapacity--;
        }
    }
    
    void printQueue()
    {
        struct node* temp = head;
        while (temp)
        {
            cout << temp->data << " -> ";
            temp= temp->next;
        }
        
        cout<<endl;
    }
};

class lruCache{
    int lruCapacity;
    queue q;
    map<int, node*> m;
    
public:
    lruCache(int n)
    {
        q.setCapacity(n);
    }
    
    void referencePage(int n)
    {
        if (m[n] == NULL)
        {
            m[n] = q.enqueue(n);
            
        }
        else{
            if (q.front()->data == n)
            {
                struct node* temp = m[n];
                q.front()->next->prev = NULL;
                q.setHead(q.front()->next);
                
                q.rear()->next = temp;
                temp->prev = q.rear();
                temp->next = NULL;
                q.setTail(q.rear()->next);
            }
            
            else if(q.rear()->data == n);
            else {
                struct node* temp = m[n];
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                
                q.rear()->next = temp;
                temp->prev = q.rear();
                q.setTail(q.rear()->next);
                
            }
        }
        
        q.printQueue();
    }
};

int main()
{
    lruCache cache(4);
    
    cache.referencePage(1);
    cache.referencePage(2);
    cache.referencePage(3);
    cache.referencePage(1);
    cache.referencePage(4);
    cache.referencePage(5);
    
    
    
    
    
    return 0;
}


















