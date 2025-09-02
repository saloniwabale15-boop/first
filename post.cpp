#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int evaluatePostfix(string expr) {
    stack<int> st;
    stringstream ss(expr);
    string token;
    
    while (ss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            // Token is a number
            st.push(stoi(token));
        } else {
            // Token is an operator
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else if (token == "/") st.push(a / b); // integer division
        }
    }
    return st.top();
}

int main() {
    string expr = "2 1 + 3 *";
    cout << evaluatePostfix(expr) << endl; // Output: 9
    return 0;
}