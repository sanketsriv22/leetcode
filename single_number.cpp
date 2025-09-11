#include <iostream>
#include "vector_helper.h"

using namespace std;

// 136. Single Number
// given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// solution must have O(n) time complexity, and only O(1) extra space

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int store;; // O(1) space
        for (int num : nums)
            store = store xor num; 
        return store;
    }
};


int main()
{
    Solution solution = Solution();

    vector<int> nums = { 1, 2, 3, 4, 4, 5 };

    int num = solution.singleNumber(nums);

    cout << num << endl;
}