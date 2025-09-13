#include <iostream>
#include "vector_helper.h"

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        return digits;
    }
};

int main()
{
    Solution solution = Solution();

    vector<int> digits = {1, 2, 3};
    vector<int> answer = solution.plusOne(digits);
    cout << answer << endl; 
}
