#include <iostream>
#include "vector_helper.h"

// 39. Combination Sum
// Given an array of distinct ints candidates, and a target int target:
// return a list of all unique combinations of candidates where the chosen numbers sum to target.
// You may return the conbinations in any order.

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> currCombination;
        backtrack(candidates, currCombination, result, 0, target);

        return result;
    }

    void backtrack(vector<int>& candidates,
                   vector<int>& currCombination,
                   vector<vector<int>>& result,
                   int startIndex,
                   int remainingTarget)
    {
        // base cases (equal or too big)
        if (remainingTarget == 0)
        {
            result.push_back(currCombination);
            return;
        } else if (remainingTarget < 0)
        {
            return; // don't add this candidate for combo
        }

        for (int i = startIndex; i < candidates.size(); i++)
        {
            // add current candidate
            currCombination.push_back(candidates[i]);
            remainingTarget -= candidates[i];

            // keep exploring
            backtrack(candidates, currCombination, result, i, remainingTarget);

            // overshot
            remainingTarget += currCombination.back();
            currCombination.pop_back();
        }
    }

};

int main()
{
    Solution solution = Solution();

    vector<int> input = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> output = solution.combinationSum(input, target);
    cout << output << endl;

    vector<int> input2 = {2, 3, 5};
    int target2 = 8;
    vector<vector<int>> output2 = solution.combinationSum(input2, target2);
    cout << output2 << endl;

    vector<int> input3 = {2};
    int target3 = 1;
    vector<vector<int>> output3 = solution.combinationSum(input3, target3);
    cout << output3 << endl;

    return 0;
}