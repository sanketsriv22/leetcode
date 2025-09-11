#include <iostream>
#include <vector>

using Vector= std::vector<int>;

class Solution {
private:
    struct twoPointer
    {
        int leftInd;
        int leftVal;
        int rightInd;
        int rightVal;
    };

    twoPointer pointers;

public:
    Solution() : pointers(0, (int)NULL, 1, (int)NULL) {}

    void moveZeroes(Vector& nums) {

        if (nums.size() == 1) { return; }

        while ( pointers.rightInd<nums.size() )
        {
            pointers.rightVal = nums[pointers.rightInd];
            pointers.leftVal = nums[pointers.leftInd];
            if (pointers.leftVal && pointers.rightVal == 0)
            {
                pointers.rightInd++;
                continue;
            }
            else if (pointers.leftVal == 0)
            {
                nums[pointers.leftInd] = pointers.rightVal;
                nums[pointers.rightInd] = pointers.leftVal;
                pointers.leftInd++;
                pointers.rightInd++;
            }
            else //if (pointers.readVal == 0)
            {
                pointers.rightInd++;
                pointers.leftInd++;
            }
        }
    }
};

int main()
{
    std::cout << "283. Move Zeroes" << std::endl;
    return 0;
}