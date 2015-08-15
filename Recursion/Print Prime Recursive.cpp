//
//  main.cpp
//  Random C++ program
//
//  Created by Daman Saroa on 16/08/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num)
{
    if (num%2 == 0) return false;
    
    else{
        for (int i=3; i<=sqrt(num); i=i+2) {
            if (num%i == 0) return false;
        }
    }
    return true;
}

void printPrime(int start, int end)
{
    if (start <= end) {
        if (start == 1) start++;
        if (isPrime(start)) cout << start << " ";
        printPrime(start+1, end);
    }
}

int main()
{
    printPrime(1, 100);
    
    return 0;
}















