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
    Solution() : pointers{0, 0, 1, 0} {}

    void moveZeroes(Vector& nums) {

        if (nums.size() == 1) { return; }

        while ( pointers.rightInd<nums.size() )
        {
            pointers.rightVal = nums[pointers.rightInd];
            pointers.leftVal = nums[pointers.leftInd];
            if (pointers.leftVal == 0 && pointers.rightVal == 0)
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
            else
            {
                pointers.rightInd++;
                pointers.leftInd++;
            }
        }
    }
};

// cool way to print a vector with overloading. probably should put this in a header file
std::ostream& operator<<(std::ostream& stream, const Vector &vector)
{
    stream << "[";
    for (size_t i = 0; i < vector.size(); i++)
    {
        stream << vector[i];
        if (i < vector.size() - 1) { stream << ", "; }
    }
    stream << "]";
    return stream;
}

int main()
{
    std::cout << "283. Move Zeroes" << std::endl;
    Solution solve = Solution();
    
    Vector test1 = Vector{0, 1, 0, 3, 12};
    
    solve.moveZeroes(test1);

    std::cout << test1 << std::endl;

    return 0;
}