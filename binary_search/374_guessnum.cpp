#include <bits/stdc++.h>
using namespace std;

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:

    int binary_search(int n)
    {
        if (n == 1) return 1;
        int start = 0;
        int end = n;

        while (start <= end)
        {
            int mid = start + (end-start)/2;
            int target;   // int target = guess(mid)  api calling
            if (target == 0)
            {
                return mid;
            }
            else if (target == -1)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return -1;
    }

    int guessNumber(int n) 
    {
        return binary_search(n);
    }
};