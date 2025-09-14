#include <iostream>
#include "vector_helper.h"

// 66. Plus One
// Given a large integer represented as an integer array digits, where each digits[i] is the ith digit of an integer.
// The digits are ordered from most significant to least significant in left-to-right order.
// The large integer does not contain any leading 0's.
// Increment the large integer by one and return the resulting array of digits.

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        int lastInd = digits.size() - 1;

        while(lastInd >= 0 && digits[lastInd] == 9)
        { 
            digits[lastInd] = 0;
            lastInd -= 1;
            
        }

        if (lastInd == -1) // special case where all digits are 9
        {
            digits.emplace(digits.begin(), 1);
        } else
        {
            digits[lastInd] = digits[lastInd] + 1;
        }

        return digits;
    }
};

int main()
{
    Solution solution = Solution();

    vector<int> digits = {1, 2, 3};
    vector<int> answer = solution.plusOne(digits);
    cout << answer << endl; 

    vector<int> digits2 = {9, 9, 9, 9, 9};
    vector<int> answer2 = solution.plusOne(digits2);
    cout << answer2 << endl; 

    vector<int> digits3 = {1, 9, 9, 9};
    vector<int> answer3 = solution.plusOne(digits3);
    cout << answer3 << endl; 

    vector<int> digits4 = {9, 9, 8, 8, 9, 9};
    vector<int> answer4 = solution.plusOne(digits4);
    cout << answer4 << endl; 
}
