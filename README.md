# Combinatorial Studies in DSA
This repository contains codes and notes shared during Classes of Combinatorial Studies in the domain of Data Structure and Algorithm (DSA).

## Course Log

| Date & Time | Topic | Concept/Algorithm | Code Reference | Description |
|-------------|-------|------------------|----------------|-------------|
| 2025-02-21 10:50 AM | Arrays | Array Input/Output | [inputArray.cpp](inputArray.cpp) | Basic implementation of array input/output operations in C++ |
| 2025-02-21 11:05 AM | Arrays | Subarray Sum | [subarraySum.cpp](subarraySum.cpp) | Calculate sum of all possible subarrays in an array |
| 2025-02-21 11:15 AM | Loops | Types of Loops | [typesOfLoops.cpp](typesOfLoops.cpp) | Different types of loops in C++ |


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

### Interview Tips
1. **Array Problems**
   - Always clarify input constraints
   - Consider edge cases (empty array, single element)
   - Look for sorting requirement
   - Check for overflow in sum calculations

2. **Loop Optimization**
   - Avoid nested loops when possible
   - Consider break conditions
   - Use appropriate loop type based on use case
   - Remember loop invariants

### Common Time Complexities
- Linear Search: O(n)
- Binary Search: O(log n)
- Nested Loops: O(n²)
- Sliding Window: O(n)