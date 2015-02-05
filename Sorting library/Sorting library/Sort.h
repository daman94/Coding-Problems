//
//  Sort.h
//  Sorting library
//
//  Created by Daman Saroa on 06/01/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#ifndef Sorting_library_Sort_h
#define Sorting_library_Sort_h
#include<iostream>
#include <algorithm>
using namespace std;

template <typename T , typename T2>

class Sort {
public:
    void bubbleSort(T* a , int low, int high , T2 obj )
    {
        int i , j;
        for (i = low; i < high; i++)
        {
            for (j= 0 ; j < high-i-1  ; j++)
            {
                if (obj.compare(a[i] , a[j] ))
                {
                    T temp = a[j];
                    a[j] = a[j+1];
                    a[j+1] = temp;
                }
            }
        }
        
    }
    
    
};
#endif
