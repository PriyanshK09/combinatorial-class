# Combinatorial Studies in DSA
This repository contains codes and notes shared during Classes of Combinatorial Studies in the domain of Data Structure and Algorithm (DSA).

## Course Log

| Date & Time | Topic | Concept/Algorithm | Code Reference | Description |
|-------------|-------|------------------|----------------|-------------|
| 2025-02-21 10:50 AM | Arrays | Array Input/Output | [inputArray.cpp](inputArray.cpp) | Basic implementation of array input/output operations in C++ |
| 2025-02-21 11:05 AM | Arrays | Subarray Sum | [subarraySum.cpp](subarraySum.cpp) | Calculate sum of all possible subarrays in an array |
| 2025-02-21 11:15 AM | Loops | Types of Loops | [typesOfLoops.cpp](typesOfLoops.cpp) | Different types of loops in C++ |
| 2025-02-21 11:25 AM | Loops | Sliding Window | [slidingWindow.cpp](slidingWindow.cpp) | Implement sliding window technique using for loop |
| 2025-02-24 09:30 AM | Two Pointers | Two Pointer Technique | [twoPointers.cpp](twoPointers.cpp) | Implement two pointer technique using while loop |

## LeetCode Problems Solved
1. "3" Longest Substring Without Repeating Characters - [Problem](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | [Solution](lengthOfLongestSubstring.cpp)
2. "11" Container with Most Water - [Problem](https://leetcode.com/problems/container-with-most-water/) | [Solution](maxArea.cpp)


## Repository Structure
```
📦 combinatorial-class
 ┣ 📜 inputArray.cpp
 ┣ 📜 subarraySum.cpp
 ┣ 📜 typesOfLoops.cpp
 ┣ 📜 ......
 ┗ 📜 README.md
```

## Getting Started
1. Clone the repository
2. Each code file contains the implementation of specific concepts
3. Compile and run C++ files using your preferred compiler

## Topics Covered
- Arrays and Array Operations
- Loops in C++
- *More topics will be added as the course progresses*

## Compilation Instructions
For C++ programs:
```bash
g++ filename.cpp -o filename
./filename
```

## Interview Preparation Notes

### 1. Arrays
#### Key Concepts
- **Array Basics**
  - Contiguous memory allocation
  - Zero-based indexing in C++
  - Fixed size declaration: `int arr[size]`
  - Time Complexity: Access O(1), Search O(n)

#### Important Operations
1. **Array Input/Output**
   ```cpp
   // Input
   for(int i = 0; i < n; i++) {
       cin >> arr[i];
   }
   // Output
   for(int i = 0; i < n; i++) {
       cout << arr[i] << " ";
   }
   ```

2. **Subarray Operations**
   - Subarray: Contiguous part of array
   - Properties:
     - For array of size n: Total subarrays = n*(n+1)/2
     - Start index ≤ End index
   - Common Problems:
     - Subarray with given sum
     - Maximum subarray sum (Kadane's Algorithm)
     - Fixed size sliding window

### 2. Loops
#### Types and Usage
1. **For Loop**
   - Best for known number of iterations
   - Counter-controlled iteration
   ```cpp
   for(initialization; condition; update) {
       // code block
   }
   ```

2. **While Loop**
   - Condition-controlled iteration
   - Used when number of iterations unknown
   ```cpp
   while(condition) {
       // code block
       // update condition
   }
   ```

#### Common Loop Patterns
1. **Sliding Window**
   ```cpp
   for(int i = 0; i < n-k+1; i++) {
       // Process window of size k
   }
   ```

2. **Two-Pointer Technique**
   ```cpp
   int i = 0, j = n-1;
   while(i < j) {
       // Process elements from both ends
   }
   ```

### 3. Sliding Window Technique
#### Key Concepts
- **Basic Principles**
  - Fixed/Variable size window
  - Linear traversal
  - Optimal for substring/subarray problems
  - Time Complexity: O(n)

#### Implementation Patterns
1. **Fixed Size Window**
   ```cpp
   // Calculate initial window
   for(int i = 0; i < k; i++) {
       windowSum += arr[i];
   }
   
   // Slide window
   for(int i = k; i < n; i++) {
       windowSum = windowSum + arr[i] - arr[i-k];
       result = max(result, windowSum);
   }
   ```

2. **Variable Size Window**
   ```cpp
   while(j < n) {
       // Add calculation for j
       
       while(condition) {
           // Remove calculation for i
           i++;
       }
       
       // Store result
       j++;
   }
   ```

### 4. String Problems
#### Important Techniques
- **Character Frequency**
  ```cpp
  int freq[128] = {0};  // for ASCII
  // or
  vector<int> freq(26, 0);  // for lowercase letters
  ```

- **Sliding Window on Strings**
  - Track unique characters
  - Maintain character count
  - Update window based on conditions

#### Common String Operations
1. **Character Counting**
   ```cpp
   string s = "example";
   vector<int> count(26, 0);
   for(char c : s) {
       count[c - 'a']++;
   }
   ```

### Interview Tips
3. **String Problems**
   - Use frequency arrays for character counting
   - Consider ASCII vs Unicode requirements
   - Check for case sensitivity
   - Handle empty string cases

4. **Sliding Window Problems**
   - Identify window condition
   - Handle window size variations
   - Track window state efficiently
   - Consider space optimization

### Common Time Complexities
- String Operations: O(n)
- Sliding Window: O(n)
- Character Frequency: O(n)
- String Comparison: O(min(n,m))