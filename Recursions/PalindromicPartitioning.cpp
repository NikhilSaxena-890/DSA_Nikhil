#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(const string& s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }

    void countPalindromicSubstrings(int ind, const string& s, int& count) {
        if (ind == s.size()) return;
        for (int i = ind; i < s.size(); i++) {
            if (isPalindrome(s, ind, i)) {
                count++;  // Count every palindromic substring
            }
        }
        countPalindromicSubstrings(ind + 1, s, count);
    }

    int countSubstrings(string s) {
        int count = 0;
        countPalindromicSubstrings(0, s, count);
        return count;
    }
};

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    Solution obj;
    cout << "Total palindromic substrings: " << obj.countSubstrings(s) << endl;

    return 0;
}
