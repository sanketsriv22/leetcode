#include <iostream>
#include "vector_helper.h"

using namespace std;

// 198. Pascal's Triangle II
// given an integer rowIndex, return the rowIndexth row of Pascal's triangle

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {

        int numRows = rowIndex + 1;
        vector<int> currRow(numRows, 1);

        for (int i = 1; i < numRows; i++)
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