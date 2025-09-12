#include <iostream>
#include "vector_helper.h"

// 35. Search Insert Position
// given a sorted array of distinct integers and a target value, return the index if the target is found.
// if not, return the index where it would be if it were inserted in order.
// algo must have O(log n) time complexity (binary search?)

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        // int size = nums.size();
        int leftBound = 0;
        int rightBound = nums.size() - 1;
        int midInd;

        while (rightBound - leftBound > 1) 
        {
            midInd = (rightBound + leftBound) / 2;
            if (nums[midInd] == target) { return midInd; } // else return the ind 
            else if (nums[midInd] > target)
            {
                // left stays same, right shifts to midPoint
                rightBound = midInd;
            } else if (nums[midInd] < target)
            {
                // right stays same, left shifts to midPoint
                leftBound = midInd;
            }
        }

        // if target isn't found
        if (target > nums[rightBound]) { return rightBound + 1; }
        else if (target < nums[leftBound]) { return (leftBound > 0 ? leftBound - 1: 0); }
        else { return (nums[leftBound] == target ? leftBound : rightBound); }
    }
};


int main()
{
    Solution solution = Solution();
    vector<int> nums = {1, 3, 5, 6};
    int target = 2;
    cout << nums << endl;
    int index = solution.searchInsert(nums, target);
    cout << index << endl;

    cout << 1/2 << endl;

    return 0;
}