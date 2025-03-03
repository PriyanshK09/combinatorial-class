#include <iostream>
#include <cmath>

class Solution {
public:
    // Method 1: Using logarithm
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        
        // Check if log base 4 of n is an integer
        double logBase4 = log10(n) / log10(4);
        return floor(logBase4) == logBase4;
    }
    
    // Method 2: Using bit manipulation
    bool isPowerOfFourBit(int n) {
        if (n <= 0) return false;
        
        // First check if it's a power of 2
        if ((n & (n - 1)) != 0) return false;
        
        // Then check if the 1 bit is at an even position (0-indexed)
        // Powers of 4 have their set bit at position 0, 2, 4, etc.
        return (n & 0x55555555) == n; // 0x55555555 is 01010101...
    }
};

int main() {
    Solution sol;
    
    // Test cases
    std::cout << "16 is power of four: " << (sol.isPowerOfFour(16) ? "true" : "false") << std::endl;
    std::cout << "5 is power of four: " << (sol.isPowerOfFour(5) ? "true" : "false") << std::endl;
    std::cout << "1 is power of four: " << (sol.isPowerOfFour(1) ? "true" : "false") << std::endl;
    
    return 0;
}