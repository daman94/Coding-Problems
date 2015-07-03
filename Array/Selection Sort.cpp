
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *arr, int n)
{
    int i, minIndex;
    for (i=0; i<n; i++)
    {
        minIndex = i;
        for (int j=i+1; j<n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        
        swap(&arr[i], &arr[minIndex]);
    }
}


int main()
{
    int arr[] = {23,1,53,81,20,64};
    int n = sizeof(arr)/sizeof(int);
    
    selectionSort(arr, n);
    
    for (int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}
