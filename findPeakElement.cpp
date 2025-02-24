#include <iostream>
#include <vector>
using namespace std;

// Leetcode Solution (Time Limit Exceeded)
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

// Optimized Solution
// Approach of this solution is to find the peak element in the array using binary search.
// If the mid element is greater than the mid + 1 element, then the peak element will be on the left side of the mid element.
// If the mid element is less than the mid + 1 element, then the peak element will be on the right side of the mid element.
// So, we will update the left and right pointers accordingly.
// We will return the left pointer as the peak element.

int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid + 1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
// Changes: if (nums[mid] > nums[mid + 1]) { right = mid; } else { left = mid + 1; }
// Time Complexity: O(log(n))

// User IO
int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << findPeakElement(nums) << endl;
    return 0;
}

// Space Complexity: O(1)