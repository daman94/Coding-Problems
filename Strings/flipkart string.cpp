//
//  main.c
//  Random C program
//
//  Created by Daman Saroa on 08/06/14.
//  Copyright (c) 2014 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;



int main()
{
    vector<string> w;
    
    int n;
    cin>>n;
    
    map<string,bool> m;
    
    for (int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        w.push_back(s);
        m[s] = true;
    }
    
    int max_count =0;
    
    for (int i=0; i<w.size(); i++)
    {
        int count=0;
        
        string s = w[i];
        
        for(int i=0;i<s.length();i++)
        {
            string temp = s.substr(0,i).append(s.substr(i+1));
            
            if(m[temp])
            {   count++;
                s= temp;
                i=0;
                max_count = max(count,max_count);
                continue;
            }
            
        }
    }
    
    cout << max_count;
    
    
    return 0;
}