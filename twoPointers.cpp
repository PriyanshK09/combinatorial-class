// What is Two Pointers?
// Two pointers is a technique where you use two pointers to traverse an array or a linked list. 
// The two pointers can move in the same direction or in opposite directions.
// The two pointers can move at the same speed or at different speeds. The two pointers can start at the same position or at different positions.
// The two pointers can be used to solve a variety of problems, such as FAMOUS PROBLEMS BELOW
// The two pointers technique is often used to solve problems that involve finding a pair of elements in an array that sum to a target value.

// Two Pointers: FAMOUS PROBLEMS IN PLACEMENT
// 1. Find the pair of elements in an array that sum to a target value
// 2. Find the pair of elements in an array that sum to a target value, with duplicates
// 3. Find the pair of elements in an array that sum to a target value, with duplicates, and return the indices
// 4. Find the pair of elements in an array that sum to a target value, with duplicates, and return the indices, with a sorted array
// 5. Find the pair of elements in an array that sum to a target value, with duplicates, and return the indices, with a sorted array, and return the first pair
// 6. Find the pair of elements in an array that sum to a target value, with duplicates, and return the indices, with a sorted array, and return the first pair, with a sorted array
// 7. Find the pair of elements in an array that sum to a target value, with duplicates, and return the indices, with a sorted array, and return the first pair, with a sorted array, and return the first pair with the smallest difference
// 8. Find the pair of elements in an array that sum to a target value, with duplicates, and return the indices, with a sorted array, and return the first pair, with a sorted array, and return the first pair with the smallest difference, with a sorted array
// 9. Find the pair of elements in an array that sum to a target value, with duplicates, and return the indices, with a sorted array, and return the first pair, with a sorted array, and return the first pair with the smallest difference, with a sorted array, and return the first pair with the smallest difference with the smallest index

#include <iostream>
#include <vector>

using namespace std;

// 1. Find the pair of elements in an array that sum to a target value
vector<int> twoSum(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            return {nums[left], nums[right]};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {};
}

// 2. Find the pair of elements in an array that sum to a target value, with duplicates
vector<int> twoSumWithDuplicates(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            return {nums[left], nums[right]};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {};
}

// 3. Find the pair of elements in an array that sum to a target value, with duplicates, and return the indices
vector<int> twoSumWithDuplicatesAndIndices(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            return {left, right};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {};
}

// 4. Find the pair of elements in an array that sum to a target value, with duplicates, and return the indices, with a sorted array
vector<int> twoSumWithDuplicatesAndIndicesAndSortedArray(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            return {nums[left], nums[right]};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {};
}

// 5. Find the pair of elements in an array that sum to a target value, with duplicates, and return the indices, with a sorted array, and return the first pair
vector<int> twoSumWithDuplicatesAndIndicesAndSortedArrayAndFirstPair(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            return {nums[left], nums[right]};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {};
}

// 6. Find the pair of elements in an array that sum to a target value, with duplicates, and return the indices, with a sorted array, and return the first pair, with a sorted array
vector<int> twoSumWithDuplicatesAndIndicesAndSortedArrayAndFirstPairAndSortedArray(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            return {nums[left], nums[right]};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {};
}

// 7. Find the pair of elements in an array that sum to a target value, with duplicates, and return the indices, with a sorted array, and return the first pair, with a sorted array, and return the first pair with the smallest difference
vector<int> twoSumWithDuplicatesAndIndicesAndSortedArrayAndFirstPairAndSortedArrayAndSmallestDifference(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            return {nums[left], nums[right]};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {};
}

// 8. Find the pair of elements in an array that sum to a target value, with duplicates, and return the indices, with a sorted array, and return the first pair, with a sorted array, and return the first pair with the smallest difference, with a sorted array
vector<int> twoSumWithDuplicatesAndIndicesAndSortedArrayAndFirstPairAndSortedArrayAndSmallestDifferenceAndSortedArray(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            return {nums[left], nums[right]};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {};
}

// 9. Find the pair of elements in an array that sum to a target value, with duplicates, and return the indices, with a sorted array, and return the first pair, with a sorted array, and return the first pair with the smallest difference, with a sorted array, and return the first pair with the smallest difference with the smallest index
vector<int> twoSumWithDuplicatesAndIndicesAndSortedArrayAndFirstPairAndSortedArrayAndSmallestDifferenceAndSortedArrayAndSmallestIndex(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            return {nums[left], nums[right]};
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}