#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

string reverseWords(string s) {
    // Remove leading and trailing spaces
    while (!s.empty() && s.front() == ' ') s.erase(s.begin());
    while (!s.empty() && s.back() == ' ') s.pop_back();

    stringstream ss(s);
    string word;
    vector<string> words;

    // Extract words (stringstream handles multiple spaces)
    while (ss >> word) {
        words.push_back(word);
    }

    // Reverse the words
    reverse(words.begin(), words.end());

    // Build the result string
    string result;
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i != words.size() - 1) result += " ";
    }

    return result;
}

int main() {
    string input = "the sky is blue";
    cout << reverseWords(input) << endl;  // Output: "blue is sky the"
    return 0;
}