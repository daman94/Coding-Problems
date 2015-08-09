//
//  main.cpp
//  Random C++ program
//
//  Created by Daman Saroa on 16/08/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#define SIZE 10
using namespace std;

template<typename T>


class vector{
    T* arr;
    int top;
    int capacity;
public:
    vector()
    {
        capacity = SIZE;
        arr = (T*)malloc(sizeof(T)*capacity);
        top = -1;
    }
    
    vector(int n)
    {
        capacity = n;
        arr = new T[capacity];
        top = -1;
    }
    
    ~vector()
    {
        capacity = 0;
        top = -1;
        free(arr);
    }
    
    int size()
    {
        return top+1;
    }
    
    void resize()
    {
        if (top >= size() ) {
            capacity *= 2;
            realloc(arr, capacity);
        }
    }
    
    void push_back(T x)
    {
        resize();
        top++;
        arr[top] = x;
    }
    
    void pop_back()
    {
        top--;
    }
    
    T Back()
    {
        if (top>=0)
            return arr[top];
        return -1;
    }
    
    T Front()
    {
        if (size()>0)
            return arr[0];
        return -1;
    }
    
    T At(int index)
    {
        return arr[index];
    }
    
    void insert(int index, T item)
    {
        if (top>=index) {
            arr[index] = item;
        }
    }
    
    int Find(T item)
    {
        for (int i=0; i<=top; i++) {
            if (arr[i] == item) {
                return i;
            }
        }
        return -1;
    }
    
    T operator[] (int i)
    {
        return arr[i];
    }
};

int main()
{
    vector<int> v;
    
    for (int i=0;i<5; i++) {
        v.push_back(i);
    }
    
    v.pop_back();
    v.pop_back();
    v.push_back(8);
    v.pop_back();
    
    for (int i=0; i<v.size();i++) {
        cout << v[i] << " ";
    }
    
    cout<<endl;
    
    
    vector<char> v1;
    v1.push_back('d');
    v1.push_back('a');
    v1.push_back('m');
    v1.push_back('a');
    v1.pop_back();
    
    for (int i=0; i<v1.size() ; i++) {
        cout << v1[i] <<" ";
    }
    return 0;
}





























