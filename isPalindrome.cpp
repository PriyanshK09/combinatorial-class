#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    while (i < j) {
        while (i < j && !isalnum(s[i])) i++;
        while (i < j && !isalnum(s[j])) j--;
        if (tolower(s[i]) != tolower(s[j])) return false;
        i++;
        j--;
    }
    return true;
}

int main()
{
    string str = "ABBBAC";
    cout << isPalindrome(str) << endl;
    return 0;
}