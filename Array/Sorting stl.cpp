//
//  main.cpp
//  Array
//
//  Created by Daman Saroa on 09/06/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    int arr[] = {4,2,6,3,1,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    sort(arr, arr+n, greater<int>() );
    
    for (int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}




























s