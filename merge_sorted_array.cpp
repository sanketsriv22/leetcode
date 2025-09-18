#include <iostream>
#include <queue>
#include "vector_helper.h"

// 88. Merge Sorted Array
// You are given to integer arrays nums1, nums2, sorted in non-decreasing order
// also given 2 integers m and n, representing # of elements in nums1, nums2 respectively
// merge nums1 and nums2 into a single array sorted in non-decreasing order

// final sorted array should by inside nums1 array. nums1 has length m+n by default. nums2 length = n = # elements

using namespace std;

class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        // BASE CASES
        if (m == 0)
        {
            for (int e = 0; e < n; e++)
            {
                nums1[e] = nums2[e];
            }
            return;
        }
        else if (n == 0) { return; }

        // SORT LOGIC
        // 2 indices, one for each array.
        int i = 0, j = 0;
        queue<int> buffer;

        
        // i goes till m, j goes till n
        while (i < nums1.size())
        {
            // if no elements in buffer and past i elements
            if (buffer.empty() && i > m - 1)
            {
                nums1[i] = nums2[j];
                i++, j++;
                continue;
            }

            // check to see if buffer has elements (use it instead of nums1[i])
            else if (!buffer.empty())
            {
                if (j >= n || buffer.front() <= nums2[j])
                {
                    if (i < m) { buffer.push(nums1[i]); }
                    nums1[i] = buffer.front();
                    buffer.pop();
                    i++;
                    continue;
                }
                else if (j < n && buffer.front() > nums2[j])
                {
                    if (i < m) { buffer.push(nums1[i]); }
                    nums1[i] = nums2[j];
                    i++, j++;
                    continue;
                }
            }

            // compare the 2 numbers and either:
            // - keep nums1 element in place, increment i
            // - add nums1 element to buffer queue, swap elements, increment j
            if (nums1[i] <= nums2[j])
            { 
                if (i < m + j + 1)
                {
                    i++;
                }
                else { nums1[i] = nums2[j]; }
            }
            else if (nums1[i] > nums2[j])
            {
                buffer.push(nums1[i]);
                nums1[i] = nums2[j];
                i++, j++;
            }
        }
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 4, 5, 6, 0};
    vector<int> nums2 = {3};
    int m = 5;
    int n = 1;
    
    Solution solution = Solution();
    solution.merge(nums1, m, nums2, n);

    cout << nums1 << endl;
    return 0;
}