//
//  main.cpp
//  Pointers
//
//  Created by Daman Saroa on 24/12/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

void strcat(char *a, char *b);
void swapFunc(char *a, char *b);

int main()
{
    //char* c= "bcf";   // why is sizeof(c) = 8??????
    
    char a[] = "daman";
    
    char b[] = "priya";
    
    swapFunc(a, b);
    
    cout << b << endl;
    
    return 0;
}

void strcat(char* a, char* b)
{
    int i=0 , j=0;
    
    while (a[i] != '\0')
    {
        i++;
    }
    
    while (b[j] != '\0')
    {
        a[i++] = b[j++];
    }
}

void swapFunc(char* a, char* b)
{
    char temp = a;
    while (*a != '\0')
    {
        *(a++) = *(b++);
    }

    b = temp;
    
    
}

























