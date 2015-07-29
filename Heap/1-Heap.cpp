//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
using namespace std;

struct heap
{
    int* array;
    int count;
    int n;
    int capacity;
};

struct heap* createHeap(int capacity)
{
    struct heap* h = (struct heap*)malloc(sizeof(struct heap));
    
    if (!h)
    {
        cout << "memory err";
        return NULL ;
    }
    
    h->capacity = capacity;
    
    h->array = (int*)malloc(sizeof(int) * capacity);
    
    if (!h->array)
    {
        cout << "memory err";
        return NULL ;
    }
    
    h->count = -1;
    
    return h;
}

int parentOfNode(struct heap* h, int i)
{
    if (i<=0 || i >= h->count)
        return -1;
    
    return (i-1)/2;
}

int leftChild(struct heap* h, int i)
{
    int left = 2*i+1;
    if (left > h->count)
    {
        return -1;
    }
    
    return left;
}

int rightChild(struct heap* h, int i)
{
    int right = 2*i+2;
    if (right > h->count)
    {
        return -1;
    }
    
    return right;
}

int getMin(struct heap* h)
{
    if (h->count == 0)
        return -1;
    
    return h->array[0];
}

int getMin (int a, int b)
{
    if (a<b)
        return a;
    else
        return b;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(struct heap* h, int i)
{
    int min;
    
    min = getMin(i, leftChild(h, i));
    min = getMin(min, rightChild(h, i));
    
    if (min!=i)
    {
        swap(&h->array[min], &h->array[i]);
        
        Heapify(h, min);
    }
}

int deleteMin(struct heap* h)
{
    if (h->count == 0)
        return -1;
    
    int data = h->array[0];
    
    h->array[0] = h->array[h->count-1];
    h->count--;
    Heapify(h, 0);
    return data;
}

void Resize(struct heap* h)
{
    h->capacity = h->capacity * 2;
    
    h->array = (int*)realloc(h->array, h->capacity);
    
}

void insert(struct heap* h, int data)
{
    if (h->count == h->capacity)
    {
        Resize(h);
    }
    
    h->count++;
    
    int i = h->count;
    
    while ( i>1 && data < h->array[(i-1)/2])
    {
        h->array[i] = h->array[(i-1)/2];
        i = (i-1)/2;
    }
    
    h->array[i] = data;
    
}

void DeleteHeap(struct heap* h)
{
    if (h)
    {
        free(h->array);
        free(h);
        h = NULL;
    }
}

void printHeap(struct heap* h)
{
    for (int i=0; i <= h->count; i++)
    {
        cout << h->array[i];
    }
}

void BuildHeap(struct heap* h, int* arr, int n)
{
    for (int i=0; i<n; i++)
    {
        h->array[i] = arr[i];
    }
    
    h->count = n;
    Heapify(h, 0);
}

//**************************  Main  ************************//
int main()
{
    struct heap* h = createHeap(2);
    
    int arr[] = {2,4,1,5,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    BuildHeap(h,arr,n);
    
    printHeap(h);
    
    return 0;
}






























