#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    stack<int> s;
    unordered_map<int, int> m;
    for (int i = 0; i < nums2.size(); i++) {
        while (!s.empty() && s.top() < nums2[i]) {
            m[s.top()] = nums2[i];
            s.pop();
        }
        s.push(nums2[i]);
    }
    vector<int> res;
    for (int i = 0; i < nums1.size(); i++) {
        res.push_back(m.count(nums1[i]) ? m[nums1[i]] : -1);
    }
    return res;
}

// Array Approach
// vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//     vector<int> res;
//     for (int i = 0; i < nums1.size(); i++) {
//         int j = 0;
//         while (nums2[j] != nums1[i]) {
//             j++;
//         }
//         j++;
//         while (j < nums2.size() && nums2[j] < nums1[i]) {
//             j++;
//         }
//         if (j == nums2.size()) {
//             res.push_back(-1);
//         } else {
//             res.push_back(nums2[j]);
//         }
//     }
//     return res;
// }

int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> res = nextGreaterElement(nums1, nums2);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}

// Output: -1 3 -1