//
//  main.c
//  Random C program
//
//  Created by Daman Saroa on 08/06/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define NA -1


using namespace std;

void moveToEnd(int *arr, int n);
void swap(int *a, int *b);
void merge(int *a, int *b, int na, int nb);

int main()
{
    int a[] = {2,NA,7,NA,NA,10,NA,NA};
    int b[] = {5,8,9,14,25};
    int nb = sizeof(b)/sizeof(b[0]);            //=5
    int na = sizeof(a)/sizeof(a[0]) - nb;   //=3
    
    cout << na<< "           ";
    
    moveToEnd(a, na+nb);
    merge(a,b,na,nb);
    
    for (int i=0; i<nb+na; i++) {
        cout << a[i]<<" ";
    }
    
    return 0;
}


//Functions

void merge(int *a, int *b, int na, int nb)
{
    int i = nb, j = 0;
    int k=0;
    while (i < na+nb && j<nb )
    {
        if (a[i] < b[j])
        {
            a[k] = a[i];
            k++;
            i++;
        }
        else
        {
            a[k] = b[j];
            k++;
            j++;
        }
    }
    
    while (i<na+nb)
    {
        a[k++] = a[i++];
    }
    while (j<nb)
    {
        a[k++] = b[j++];
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}



void moveToEnd(int *a, int n)
{
    int i = 0;
    int j = n-1;
    
    for (i=n-1; i>=0; i--)
    {
        if (a[i] != NA)
        {
            a[j] = a[i];
            j--;
        }
    }
}



