#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int maxArea = 0;

    while (left < right) {
        // Calculate the current area, which is the minimum of the two heights multiplied by the distance between the two heights
        int currentArea = min(height[left], height[right]) * (right - left);
        // Update the maximum area
        maxArea = max(maxArea, currentArea);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return maxArea;
}

int main() {
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << maxArea(height) << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)

// Output: 49

// Explanation: 
// The maximum area is obtained by choosing the minimum of the two heights and multiplying it by the distance between the two heights.
// The maximum area is 49.