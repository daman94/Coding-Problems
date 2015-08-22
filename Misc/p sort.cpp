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

struct children{
    string name;
    int height;
    int weight;
    
    children(){};
    
    children(string n,int h,int w){
        name = n ;
        height = h;
        weight = w;
    }
};

bool compare(children c1,children c2){
    
    return c1.weight<c2.weight;
}

int main(){
    children c[10];
    c[0] = children("daman",5,46);
    c[1] = children("khushdil",6,55);
    c[2]= children("priyam",4,34);
    c[3] = children("ricky",7,80);
    c[4] = children("prateek",6,60);
    
    sort(c,c+5,compare);
    
    for (int i=0;i<5; i++)
    {
        cout << c[i].name << " ";
    }
    
    
}