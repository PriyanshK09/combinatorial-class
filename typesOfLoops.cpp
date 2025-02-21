// Maximum possivle subarray with size K, using every type of loop

#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];

    // Input in FOR loop
    // for(int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }

    // Input in WHILE loop
    int i = 0;
    while(i < n) {
        cin >> arr[i];
        i++;
    }

    int maxSum = 0;

    // Nested FOR loop
    for(int i = 0; i < n - k + 1; i++) {
        int sum = 0;
        for(int j = 0; j < k; j++) {
            sum += arr[i + j];
        }
        maxSum = max(maxSum, sum);
    }

    // Nested WHILE loop
    // int i = 0;
    // while(i < n - k + 1) {
    //     int sum = 0;
    //     int j = 0;
    //     while(j < k) {
    //         sum += arr[i + j];
    //         j++;
    //     }
    //     maxSum = max(maxSum, sum);
    //     i++;
    // }
    
    cout << maxSum << endl;
    return 0;
}