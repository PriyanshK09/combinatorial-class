#include <iostream>
#include <vector>
using namespace std;

class NumArray
{
public:
    vector<int> sums;

    NumArray(vector<int> &nums)
    {
        sums.resize(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++)
        {
            sums[i + 1] = sums[i] + nums[i];
        }
    }

    int sumRange(int i, int j)
    {
        return sums[j + 1] - sums[i];
    }
};

// How this works: 
// The idea is to store the sum of the first i elements in the sums array.
// Then, to calculate the sum of elements between indices i and j, we can directly use the sums array.
// The sum of elements between i and j is given by sums[j + 1] - sums[i].
// This is because sums[j + 1] stores the sum of the first j elements, and sums[i] stores the sum of the first i elements.
// Therefore, the sum of elements between i and j is the difference between the sum of the first j elements and the sum of the first i elements.