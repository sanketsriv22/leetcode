#include <iostream>
#include "vector_helper.h"

using namespace std;

// 198. Pascal's Triangle II
// given an integer rowIndex, return the rowIndexth row of Pascal's triangle

// solution has space complexity O(rowIndex+1)

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> currRow(rowIndex + 1, 1);
        for (int i = 1; i < rowIndex + 1; i++)
        {
            for (int j = i - 1; j > 0; j--)
            {
                currRow[j] = currRow[j-1] + currRow[j];
            }
        }
        return currRow;
    }
};


int main()
{
    int rowIndex = 4;
    Solution solution = Solution();
    vector<int> row = solution.getRow(rowIndex);
    cout << row << endl;
    cout << "Done" << endl;
}