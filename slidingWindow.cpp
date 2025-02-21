#include <bits/stdc++.h>
using namespace std;

// Basic Sliding Window Algorithm Approach

void findSubarray(int arr[], int n, int k) {
    int sum = 0;
    int maxSum = INT_MIN;
    
    // First window
    for (int i = 0; i < k; i++)
        sum += arr[i];
    
    maxSum = sum;
    
    // Slide window
    for (int i = k; i < n; i++) {
        sum = sum + arr[i] - arr[i-k];
        maxSum = max(sum, maxSum);
    }
    
    cout << "Maximum sum of subarray of size " << k << " is: " << maxSum;
}

int main() {
    int arr[] = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int k = 4;
    int n = sizeof(arr) / sizeof(arr[0]);
    
    findSubarray(arr, n, k);
    return 0;
}