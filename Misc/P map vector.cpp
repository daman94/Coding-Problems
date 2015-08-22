
//
//  main.cpp
//  Random C++ program
//
//  Created by Daman Saroa on 03/08/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <stdio.h>



#include<iostream>
#include<map>
#include<string>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

class compare{
public:
    bool operator()(const int&a,const int&b ){
        return a>b;
    }
};

int main(){
    string s;
    cin>>s;
    
    map<char, int> m;
    for(int i=0;i<s.length();i++){
        m[s[i]]++;
    }
    
    for(int i=0;i<s.length();i++){
        if(m[s[i]]==1){
            cout<<s[i]<<endl;
            break;
        }
    }
    
    priority_queue<int,vector<int>,compare> pq;
    pq.push(1);
    pq.push(7);
    pq.push(3);
    
    cout<<pq.top();
    pq.pop();
    cout<<pq.top();
    pq.pop();
    
    
    return 0;
}