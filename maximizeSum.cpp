#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::sort(strs.begin(), strs.end());
        int a = strs.size();
        std::string n = strs[0], m = strs[a-1], ans = "";
        for(int i = 0; i < n.size(); i++) {
            if(n[i] == m[i]) {
                ans += n[i];
            }
            else break;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    std::vector<std::string> strs1 = {"flower", "flow", "flight"};
    std::cout << "Test 1: " << solution.longestCommonPrefix(strs1) << std::endl;
    
    // Test case 2
    std::vector<std::string> strs2 = {"dog", "racecar", "car"};
    std::cout << "Test 2: " << solution.longestCommonPrefix(strs2) << std::endl;
    
    return 0;
}