#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    int n = heights.size();
    for (int i = 0; i <= n; i++) {
        while (!s.empty() && (i == n || heights[i] < heights[s.top()])) {
            int h = heights[s.top()];
            s.pop();
            int l = s.empty() ? -1 : s.top();
            maxArea = max(maxArea, h * (i - l - 1));
        }
        s.push(i);
    }
    return maxArea;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << largestRectangleArea(heights) << endl;
    return 0;
}