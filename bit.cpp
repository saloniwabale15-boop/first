#include <bits/stdc++.h>
using namespace std;

int atMostKDistinct(string s, int k) {
    unordered_map<char, int> freq;
    int left = 0, count = 0;
    for (int right = 0; right < s.size(); right++) {
        freq[s[right]]++;
        while (freq.size() > k) {
            freq[s[left]]--;
            if (freq[s[left]] == 0) freq.erase(s[left]);
            left++;
        }
        count += right - left + 1;
    }
    return count;
}

int countSubstringsWithKDistinct(string s, int k) {
    return atMostKDistinct(s, k) - atMostKDistinct(s, k - 1);
}

int main() {
    string s = "pqpqs";
    int k = 2;
    cout << countSubstringsWithKDistinct(s, k) << endl;
    return 0;
}