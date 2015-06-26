//
//  main.c
//  Random C program
//
//  Created by Daman Saroa on 08/06/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MAX 10000

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}



int main()
{
    int a[] = {27,-233,-1,3,20,-40,10,-12};
    int n = sizeof(a)/sizeof(int);
    
    sort(a, a+n);
    
    for (int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }
    
    int l=0, r=n-1;
    
    int absMinSum = MAX;
    
    while (l<r)
    {
        if (a[l] + a[r] > 0)
        {
            if (absMinSum > abs(a[l]+a[r]) )
            {
                absMinSum = abs(a[l]+a[r]);
            }
            r--;
        }
        
        else
        {
            if (absMinSum > abs(a[l]+a[r]) )
            {
                absMinSum = abs(a[l]+a[r]);
            }
            l++;
        }
    }
    
    
    cout << endl;
    
    cout << absMinSum;
    
    return 0;
}