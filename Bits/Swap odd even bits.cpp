Bit //
//  main.cpp
//  Random C++ program
//
//  Created by Daman Saroa on 01/09/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <bitset>
using namespace std;

unsigned int swapBits(unsigned int x)
{
    unsigned int even = x & 10101010101010;
    unsigned int odd = x &  0x5555555555;
    
    std::bitset<16> a(even);
    std::bitset<16> b(odd);
    
    cout << "e: "<<a<<endl;
    
    cout << "o: "<<b<<endl;
    even = even >> 1;
    odd = odd << 1;
    
    
    return even| odd;
}


int main()
{
    unsigned int x = 23;
    
    std::bitset<16> y(x);
    cout<<"x: "<<y<<endl;
    
    cout<<endl;
    
    cout<< swapBits(x);
    
    return 0;
}