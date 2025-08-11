#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int start = 0;
        int middle = 0;
        int end = nums.size() - 1;

        while (middle <= end)        //dnf algo
        {
            switch(nums[middle])
            {
                case 0:
                    swap(nums[start], nums[middle]);
                    middle++;
                    start++;
                    break;

                case 1:
                    middle++;
                    break;

                case 2:
                    swap(nums[middle], nums[end]);
                    end--;
                    break;
            }
        }
    }
};