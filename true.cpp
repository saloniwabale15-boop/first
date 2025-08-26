#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    unordered_map<char, char> mp = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char c : s) {
        // If it's a closing bracket
        if (mp.find(c) != mp.end()) {
            if (!st.empty() && st.top() == mp[c]) {
                st.pop();  // valid pair, remove last opening bracket
            } else {
                return false; // mismatch found
            }
        } else {
            // Opening bracket, push onto stack
            st.push(c);
        }
    }

    return st.empty(); // Valid if no unmatched brackets remain
}

int main() {
    string s;
    cout << "Enter a string of brackets: ";
    cin >> s;

    if (isValid(s))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}