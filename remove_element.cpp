#include <iostream>
#include "vector_helper.h"

// 27. Remove Element

// given an integer array nums and an integer val, remove all occurrences of val in nums in-place.
// The order of the elements may be changed.
// Then return the number of elements in nums which are not equal to val.

using namespace std;

class Solution
{
public:
    int removeElement(vector<int>& nums, int val)
    {
        for (int i = nums.size(); i >= 0; i--)
        {
            if (nums[i] == val) { nums.erase(nums.begin() + i); };
        }
        return nums.size();
    }
};

int main()
{
    Solution solution = Solution();

    vector<int> nums = {1, 2, 3, 4, 5};
    int val = 3;

    int answer = solution.removeElement(nums, val);

    cout << nums << endl;
    cout << answer << endl;

    return 0;
}