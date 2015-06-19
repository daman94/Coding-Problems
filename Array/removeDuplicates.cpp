//
//  main.c
//  Random C program
//
//  Created by Daman Saroa on 08/06/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//

#include <iostream>
#define MAX 100000
using namespace std;


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void removeDuplicates(int *array, int size) {
    
    bool hashMap[MAX] = {0};
    
    int j=0;
    
    for (int i=0; i<size; i++)
    {
        if (hashMap[array[i]] == 0)
        {
            hashMap[array[i]] = 1;
            swap(&array[i], &array[j]);
            j++;
        }
    }
    
    for (int i=0; i<j; i++) {
        cout << array[i] << " ";
    }

    
}


int main(void)
{
    int array[] = {1,2,1,4,6,1,1,2,2,2,4,4,7,2};
    int size = sizeof(array)/sizeof(int);
    
    removeDuplicates(array, size);
    
    return 0;
}

