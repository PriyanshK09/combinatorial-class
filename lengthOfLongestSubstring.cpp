// Leetcode 3. Longest Substring Without Repeating Characters
// Given a string s, find the length of the longest substring without duplicate characters.

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    if(s.size() == 0 || s.size() == 1) return s.size();
    int arr[128] = {0};
    int i = 0, j = 1;
    arr[s[0]] = 1;
    int ans = j-i;
    while(j < s.size())
    {
        if(arr[s[j]] == 0) arr[s[j]] = j+1;
        else
        {
            if(arr[s[j]] >= i) i = arr[s[j]];
            arr[s[j]] = j+1;
        }
        j++;
        ans = max(j-i, ans);
    }
    return ans;
}

int main()
{
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}