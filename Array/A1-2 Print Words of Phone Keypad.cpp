//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <list>
#include <cstring>

using namespace std;

typedef list<string> LinkedList;
LinkedList myList;

//hashtable of 1-9 numbers
const char hashTable[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void printLinkedList(LinkedList l)
{
    LinkedList::iterator it;
    for (it=l.begin(); it != l.end(); it++)
    {
        cout << (*it) << " ";
    }
    
    cout<<endl;
}

void printWordsUtil(int *num, int size, char *output, int current)
{
    int i;
    
    if (current == size)
    {
        myList.push_back(output);
        
        printf("%s ", output);
        return;
    }
    
    for (i=0; i<strlen(hashTable[num[current]]); i++)
    {
        if (num[current] == 0 || num[current]==1)
        {
            return;
        }
        output[current] = hashTable[num[current]][i];
        printWordsUtil(num, size, output, current+1);
    }
    
}

void printWords(int *num, int size)
{
    char output[size+1];
    output[size] = '\0';
    
    printWordsUtil(num, size, output, 0);
    
}

int main()
{
    int number[] = {2,3};
    int size = sizeof(number)/sizeof(number[0]);
    
    printWords(number, size);
    
    return 0;
}



