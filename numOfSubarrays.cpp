#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int odd = 0, even = 1;
        int sum = 0, res = 0;
        // sum = 0 means the subarray is even
        // res is the number of subarrays

        // Implementation of the loop:
        // If the sum is even, then the subarray is even, so we add the number of odd subarrays to the result
        // If the sum is odd, then the subarray is odd, so we add the number of even subarrays to the result
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (sum % 2 == 0) {
                res = (res + odd) % 1000000007;
                even++;
            } else {
                res = (res + even) % 1000000007;
                odd++;
            }
        }

        // Why do we need to return res % 1000000007?
        // Because the answer can be very large
        return res % 1000000007;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 3, 5};
    cout << sol.numOfSubarrays(arr) << endl;
    return 0;
}