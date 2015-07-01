//
//  main.c
//  Random C program
//
//  Created by Daman Saroa on 08/06/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

void swap(int *a, int *b);
int findGcd(int a, int b);
void leftRotate(int *arr, int n, int d);


int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9,10,11,12};
    int n= sizeof(a)/sizeof(a[0]);
    
    int d = 2;
    
    leftRotate(a, n, d);
    
    for (int i=0; i<n; i++)
    {
        cout << a[i]<<" ";
    }
    
    return 0;
}


//Functions
int findGcd(int a, int b)
{
    if (b==0)
    {
        return a;
    }
    
    return findGcd(b, a%b);
}

void leftRotate(int *arr, int n, int d)
{
    int gcd = findGcd(n, d);
    int temp,i,j,k;
    for (i=0; i<gcd; i++)
    {
        temp = arr[i];
        
        j=i;
        while (j+d <n)
        {
            k= j+d;
            arr[j] = arr[k];
            j=k;
        }
        arr[j]=temp;
    }
    
}























