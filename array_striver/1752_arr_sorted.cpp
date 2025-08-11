#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int counter=0;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[i-1]) counter++;
                

        }
        if (nums[n-1]>nums[0]) counter++;
        return counter<=1;
        
    }
};


/*The function takes a vector of integers nums as input.
It initializes a variable count to keep track of the number of occurrences where an element is greater than its next element.
The loop iterates through the vector from index 1 to n-1, comparing each element with its previous element. If an element is greater than its previous element, the count is incremented.
After the loop, it checks whether the last element (nums[n-1]) is greater than the first element (nums[0]). If so, it increments the count.
Finally, the function returns true if count is less than or equal to 1, indicating that the vector is either sorted in non-decreasing order or has only one inversion. */