#include <iostream>
#include "vector_helper.h"

using namespace std;

// 118. Pascal's Triangle
// given an integer numRows, return the first numRows of Pascal's triangle

class Solution
{
public:
    vector<vector<int>> generateTriangle(int numRows)
    {
        vector<vector<int>> triangle;
        triangle.reserve(numRows);

        for (int i = 1; i <= numRows; i++)
        {
            vector<int> currRow(i, 1); // size i, all equal to 1
                
            for (int j = 1; j < i - 1; j++)
                {
                    currRow[j] = triangle[i-2][j-1] + triangle[i-2][j];
                }    

            triangle.push_back(currRow);
        }

        return triangle; 
    }
};



int main()
{
    int numRows = 5;
    Solution solution = Solution();
    vector<vector<int>> triangle = solution.generateTriangle(5);
    cout << triangle << endl;
    cout << "Done" << endl;
}