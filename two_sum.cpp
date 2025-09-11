#include <iostream>
#include "vector_helper.h"

using namespace std; // only doing this bc it's leetcode

// given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target
// assume each input has exactly one solution
// return in any order

class Solution 
{
private:
    vector<int> indices;
    vector<int> values;

    void ResetIndices()
    {
        indices[0] = 0;
        indices[1] = 1;
    }
public:
    Solution() : indices{0, 1}, values{0, 0} {}

    vector<int> twoSum(vector<int>& nums, int target)
    {
        ResetIndices();

        int sum;

        while (indices[0] < nums.size() - 1)
        {
            values[0] = nums[indices[0]];
            values[1] = nums[indices[1]];
            
            sum = values[0] + values[1];

            if (sum == target) { return indices; }
            else { indices[1]++; }
            
            if (indices[1] == nums.size()) // reset for next pass
            { 
                indices[0]++;
                indices[1] = indices[0] + 1;
            }
        }

        return indices;
    }
};

int main()
{
    Solution solution = Solution();

    vector<int> nums1 = {2, 7, 11, 15};
    vector<int> nums2 = {3, 2, 4};
    vector<int> nums3 = {3, 3};

    int target1 = 9;
    int target2 = 6;
    int target3 = 6;

    vector<int> answer1 = solution.twoSum(nums1, target1);
    vector<int> answer2 = solution.twoSum(nums2, target2);
    vector<int> answer3 = solution.twoSum(nums3, target3);

    cout << answer1 << endl;
    cout << answer2 << endl;
    cout << answer3 << endl;

    return 0;
}