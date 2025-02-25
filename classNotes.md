# C++ Class Notes - Combinatorial Studies in DSA

## Arrays and Array Operations

### Array Fundamentals
- **Definition**: Contiguous memory allocation for elements of the same data type
- **Declaration**: `data_type array_name[size];`
- **Access Pattern**: Zero-indexed (first element at index 0)
- **Memory Allocation**: 
  - Static arrays: Fixed size determined at compile time
  - Dynamic arrays: Size determined at runtime using `new` operator

### Array Input/Output Operations
```cpp
// Array declaration
int arr[5];

// Input elements
for(int i = 0; i < 5; i++) {
    cin >> arr[i];
}

// Output elements
for(int i = 0; i < 5; i++) {
    cout << arr[i] << " ";
}
```

### Vector Container
- **Advantages over arrays**:
  - Dynamic resizing
  - Built-in methods for common operations
  - Part of Standard Template Library (STL)

```cpp
// Vector declaration & initialization
vector<int> vec;
vector<int> vec2(5, 0);  // 5 elements initialized to 0

// Adding elements
vec.push_back(10);  // Adds element at the end

// Accessing elements
int first = vec[0];      // Direct access (no bounds checking)
int second = vec.at(1);  // Access with bounds checking

// Size operations
int size = vec.size();
vec.resize(10);
```

### Subarray Operations
- **Definition**: A contiguous part of an array
- **Number of subarrays**: For an array of size n, there are n*(n+1)/2 possible subarrays

#### Calculating Sum of All Subarrays
```cpp
// Brute force approach: O(n³)
void printSubarraySum(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            int sum = 0;
            for(int k = i; k <= j; k++) {
                sum += arr[k];
            }
            cout << "Sum of subarray [" << i << "," << j << "]: " << sum << endl;
        }
    }
}

// Optimized approach: O(n²)
void printSubarraySum(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += arr[j];
            cout << "Sum of subarray [" << i << "," << j << "]: " << sum << endl;
        }
    }
}
```

## Loop Variations in C++

### For Loop
- **Syntax**: `for(initialization; condition; update) { /* body */ }`
- **Use Cases**: When number of iterations is known beforehand
- **Example**:
```cpp
for(int i = 0; i < n; i++) {
    // Loop body
}
```

### While Loop
- **Syntax**: `while(condition) { /* body */ }`
- **Use Cases**: When iterations depend on a condition
- **Example**:
```cpp
int i = 0;
while(i < n) {
    // Loop body
    i++;
}
```

### Do-While Loop
- **Syntax**: `do { /* body */ } while(condition);`
- **Use Cases**: When you need at least one execution of the loop
- **Example**:
```cpp
int i = 0;
do {
    // Loop body
    i++;
} while(i < n);
```

### Range-Based For Loop (C++11)
- **Syntax**: `for(declaration : range) { /* body */ }`
- **Use Cases**: Iterating through containers
- **Example**:
```cpp
vector<int> vec = {1, 2, 3, 4, 5};
for(int x : vec) {
    cout << x << " ";
}
```

### Iterator Usage
```cpp
vector<int> vec = {1, 2, 3, 4, 5};
for(auto it = vec.begin(); it != vec.end(); it++) {
    cout << *it << " ";
}
```

## Two Pointer Technique

### Overview
- An algorithm where two pointers iterate through the data structure in tandem
- Often used to search pairs in a sorted array or to process subarrays

### When to Use
- Finding pairs with a given sum in a sorted array
- Removing duplicates from a sorted array
- Finding the longest substring without repeating characters
- Container with most water problem

### Implementation
```cpp
// Example: Find pair with given sum in sorted array
bool findPair(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    
    while(left < right) {
        int currentSum = nums[left] + nums[right];
        
        if(currentSum == target) {
            return true;  // Pair found
        }
        else if(currentSum < target) {
            left++;  // Need a larger sum, move left pointer
        }
        else {
            right--;  // Need a smaller sum, move right pointer
        }
    }
    
    return false;  // No pair found
}
```

### Common Patterns
1. **Opposite directional**: One pointer at beginning, one at end (as shown above)
2. **Same directional**: Both pointers moving in the same direction
    ```cpp
    // Example: Remove duplicates from sorted array
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        
        int slow = 0;
        for(int fast = 1; fast < nums.size(); fast++) {
            if(nums[fast] != nums[slow]) {
                slow++;
                nums[slow] = nums[fast];
            }
        }
        
        return slow + 1;  // New length
    }
    ```

## Sliding Window Technique

### Overview
- A computational technique that aims to reduce the use of nested loops
- Converts two nested loops into a single loop, improving time complexity

### Types of Sliding Windows
1. **Fixed-size window**: The window size remains constant
2. **Variable-size window**: The window size changes based on certain conditions

### Fixed-Size Window Implementation
```cpp
// Example: Find max sum subarray of size k
int maxSumSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    
    // Base case
    if(n < k) return -1;
    
    // Compute sum of first window
    int windowSum = 0;
    for(int i = 0; i < k; i++) {
        windowSum += nums[i];
    }
    
    int maxSum = windowSum;
    
    // Slide the window
    for(int i = k; i < n; i++) {
        windowSum = windowSum + nums[i] - nums[i-k];
        maxSum = max(maxSum, windowSum);
    }
    
    return maxSum;
}
```

### Variable-Size Window Implementation
```cpp
// Example: Smallest subarray with sum >= target
int smallestSubarrayWithSum(vector<int>& nums, int target) {
    int n = nums.size();
    int minLength = INT_MAX;
    
    int left = 0;
    int sum = 0;
    
    for(int right = 0; right < n; right++) {
        sum += nums[right];
        
        // Shrink window from left if condition is met
        while(sum >= target) {
            minLength = min(minLength, right - left + 1);
            sum -= nums[left];
            left++;
        }
    }
    
    return (minLength != INT_MAX) ? minLength : 0;
}
```

## Memory Management in C++

### Stack vs Heap
- **Stack**:
  - Memory allocated during compile time
  - Fast allocation and deallocation
  - Limited size
  - Automatically managed
  
- **Heap**:
  - Memory allocated during runtime
  - Slower allocation and deallocation
  - Larger size
  - Manually managed (need to free/delete)

### Smart Pointers (C++11)
- **Types**:
  - `std::unique_ptr`: Exclusive ownership
  - `std::shared_ptr`: Shared ownership
  - `std::weak_ptr`: Non-owning reference

```cpp
// unique_ptr example
std::unique_ptr<int> ptr1(new int(5));
auto ptr2 = std::make_unique<int>(10);  // C++14

// shared_ptr example
std::shared_ptr<int> ptr3 = std::make_shared<int>(15);
auto ptr4 = ptr3;  // Both point to the same object
```

### Reference Variables
- Alias to another variable
- Must be initialized when declared
- Cannot be changed to refer to another variable

```cpp
int x = 10;
int& ref = x;  // ref is a reference to x

ref = 20;  // x is now 20
```

## STL Containers and Algorithms

### Vector Operations
```cpp
// Initialization
vector<int> v = {1, 2, 3};

// Insertion
v.push_back(4);     // Add to end
v.insert(v.begin(), 0);  // Insert at beginning

// Removal
v.pop_back();       // Remove last element
v.erase(v.begin()); // Remove first element

// Accessing
int front = v.front();  // First element
int back = v.back();    // Last element

// Size operations
int size = v.size();
bool isEmpty = v.empty();
v.clear();  // Remove all elements
```

### Array Methods (C++11)
```cpp
std::array<int, 5> arr = {1, 2, 3, 4, 5};

// Similar methods to vector
int first = arr.front();
int last = arr.back();
int size = arr.size();

// Direct access
int third = arr[2];
int third_safe = arr.at(2);  // With bounds checking
```

### Useful Algorithms
```cpp
vector<int> v = {5, 2, 8, 1, 9};

// Sorting
sort(v.begin(), v.end());  // [1, 2, 5, 8, 9]

// Binary search on sorted container
bool found = binary_search(v.begin(), v.end(), 5);  // true

// Finding elements
auto it = find(v.begin(), v.end(), 5);
if(it != v.end()) {
    cout << "Found at position: " << (it - v.begin()) << endl;
}

// Min/Max elements
auto minIt = min_element(v.begin(), v.end());
auto maxIt = max_element(v.begin(), v.end());

// Accumulate (sum)
int sum = accumulate(v.begin(), v.end(), 0);
```

## Optimization Tips for C++

### Avoiding Copies
- Pass by reference or const reference instead of by value
```cpp
// Inefficient - makes a copy
void process(vector<int> v) { /* ... */ }

// Efficient - no copy
void process(vector<int>& v) { /* ... */ }

// Safer - no copy and can't modify
void process(const vector<int>& v) { /* ... */ }
```

### Reference Parameters
- Use when you need to modify the original
- Use const reference when you don't need to modify

### Const Correctness
- Mark functions as `const` when they don't modify object state
- Mark parameters as `const` when they won't be modified
- Helps compiler optimization and prevents bugs

```cpp
class MyClass {
public:
    int getValue() const { return value; }  // Won't modify object
private:
    int value;
};
```

### Compiler Optimizations
- Use `-O2` or `-O3` flags for release builds
- Consider inline functions for small, frequently called functions
- Avoid unnecessary branching in critical loops

## Common Time Complexities

### String Operations
- String Length: O(1) for std::string, O(n) for C-style strings
- String Concatenation: O(n+m) where n and m are string lengths
- Substring: O(m) where m is substring length

### Arrays
- Access by index: O(1)
- Search unsorted: O(n)
- Search sorted: O(log n) using binary search
- Insert/Delete at end: O(1) amortized for vector
- Insert/Delete in middle: O(n)

### Sliding Window
- Typical implementation: O(n)

### Two Pointer
- Typical implementation: O(n)

### Sorting
- std::sort: O(n log n)
- Bubble, Insertion, Selection sort: O(n²)
- Merge, Quick sort: O(n log n)

## LeetCode Problems Covered

### 1. Longest Substring Without Repeating Characters
- **Problem**: Find the length of the longest substring without repeating characters
- **Approach**: Sliding window with a hashmap/array to track character positions
- **Time Complexity**: O(n)
- **Space Complexity**: O(min(m, n)) where m is the size of the character set
- **Key Concepts**: Variable-size sliding window, character frequency tracking

### 2. Container with Most Water
- **Problem**: Find two lines that together with the x-axis form a container that holds the most water
- **Approach**: Two-pointer technique
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)
- **Key Concepts**: Area calculation, greedy approach

### 3. Find Peak Element
- **Problem**: Find a peak element (an element greater than its neighbors)
- **Approach**: Binary search
- **Time Complexity**: O(log n)
- **Space Complexity**: O(1)
- **Key Concepts**: Modified binary search, peak finding

### 4. Range Sum Query - Immutable
- **Problem**: Calculate the sum of elements between indices i and j
- **Approach**: Prefix Sum
- **Time Complexity**: O(1) per query after O(n) preprocessing
- **Space Complexity**: O(n)
- **Key Concepts**: Prefix sum, preprocessing for query optimization

### 5. Number of Sub-arrays With Odd Sum
- **Problem**: Count number of sub-arrays with odd sum
- **Approach**: Keep track of odd and even sum counts
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)
- **Key Concepts**: Mathematical properties of odd/even sums, prefix sum concept

### 6. Design Linked List
- **Problem**: Implement a singly linked list
- **Approach**: Create Node structure and LinkedList class
- **Time Complexity**: O(1) for add/delete at head, O(n) for other operations
- **Space Complexity**: O(n)
- **Key Concepts**: Linked list data structure, pointer manipulation

## Advanced Topics (Preview of Upcoming Sessions)

### Dynamic Programming
- Overlapping subproblems
- Optimal substructure
- Memoization vs Tabulation

### Graph Algorithms
- Depth-First Search (DFS)
- Breadth-First Search (BFS)
- Dijkstra's Algorithm
- Minimum Spanning Tree

### Backtracking
- Combinatorial problems
- N-Queens problem
- Subset generation

### Greedy Algorithms
- Activity selection
- Huffman coding
- Fractional Knapsack

### Useful Resources
- [C++ Reference](https://en.cppreference.com/)
- [GeeksforGeeks](https://www.geeksforgeeks.org/)
- [LeetCode](https://leetcode.com/)
- "Introduction to Algorithms" by Cormen, Leiserson, Rivest, and Stein
- "Effective C++" by Scott Meyers