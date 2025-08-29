#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> lastSeen;
    int left = 0, maxLen = 0;

    for (int right = 0; right < s.size(); right++) {
        if (lastSeen.find(s[right]) != lastSeen.end() && lastSeen[s[right]] >= left) {
            left = lastSeen[s[right]] + 1;  // move left pointer
        }
        lastSeen[s[right]] = right;  // update last seen index
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}

int main() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl; // Output: 3
    return 0;
}