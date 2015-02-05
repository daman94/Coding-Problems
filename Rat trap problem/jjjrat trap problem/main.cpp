//
//  main.cpp
//  jjjrat trap problem
//
//  Created by Daman Saroa on 02/01/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

struct box {
    int i;
    int j;
};

void func(int arr[][4], int src, int dest)
{
    struct box obj;
    obj.i = 0;
    obj.j = 0;
    queue<box> q;
    
    q.push(obj);
    
    while (!q.empty())
    {
        box obj2;
        obj2 = q.front();
        q.pop();
        
        int item = arr[obj2.i][obj2.j];
        int left = arr[obj2.i][(obj2.j)+1];
        int right = arr[(obj2.i)+1][obj2.j];
        
        if (left != -1 && left < item)
        {
            arr[obj2.i][(obj2.j)+1] = item + 1;
        }
        
        if (right != -1 && right < item)
        {
            arr[(obj2.i)+1][obj2.j] = item + 1;
        }
        
        q.push();
        q.push();
    }
    
}

int main()
{
    int arr[][4] = { {0,0,0,-1},
                    {-1,0,-1,-1},
                    {0,0,0,-1},
                    {-1,-1,0,0} };
    
    func(arr, 0, 4);
    
    for (int i = 0; i<4; i++)
    {
        for (int j=0; j<4; j++) {
            cout << arr[i][j] << " ";
        }
        
        cout << endl;
    }
    
    return 0;
}

























