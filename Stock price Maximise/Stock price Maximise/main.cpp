//
//  main.cpp
//  Stock price Maximise
//
//  Created by Daman Saroa on 10/01/15.
//  Copyright (c) 2015 Daman Saroa. All rights reserved.
//

#include <iostream>
using namespace std;

void func(int arr[], int n)
{
    int min = arr[0] , max = arr[0] , profit =0;
    
    for (int i=0; i<n-1; i++)
    {
        if (arr[i+1] > arr[i])
        {
            max = arr[i+1];
        }
        
        else
        {
            profit = profit + (max - min);
            min = arr[i+1];
        }
    }
    
    profit = profit + (max - min);

    cout << "the profit is " << profit << endl;
    
}

int main()
{
    int arr[] = {2,4,3,6,8,1,7};
    int n = sizeof(arr) / sizeof(int);
    func(arr, n);
    
    return 0;
}