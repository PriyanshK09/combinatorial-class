#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> res(T.size(), 0);
    stack<int> s;
    for (int i = 0; i < T.size(); i++) {
        while (!s.empty() && T[i] > T[s.top()]) {
            int t = s.top();
            s.pop();
            res[t] = i - t;
        }
        s.push(i);
    }
    return res;
}

int main() {
    vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> res = dailyTemperatures(T);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}