/* algorithm : 
1) find the mid
2) compare the mid with the key element
3) if equal then return or we will get the left part or the right part of the array
4) again go to the first step*/

#include <iostream>
using namespace std;

int bs(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;

    int mid = start + (end - start)/2;

    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }

        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }

        mid = start + (end - start)/2;
    }
    return -1;
}

//complexity : o(log n)

bool bsrec(int arr[], int start, int end, int k)
{
    if(start > end)
    {
        return false;
    }

    int mid = start + (end - start)/2;

    if (k > arr[mid])
    {
        return bsrec(arr, mid + 1, end, k);
    }
    else
    {
        return bsrec(arr, start, mid-1, k);
    }
}