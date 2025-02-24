#include <iostream>
#include <vector>
using namespace std;

// Leetcode Solution
int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

// User IO
int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << findPeakElement(nums) << endl;
    return 0;
}