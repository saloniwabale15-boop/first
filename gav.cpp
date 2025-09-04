#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& st, int item) {
    if (st.empty()) {
        st.push(item);
        return;
    }
    int temp = st.top(); st.pop();
    insertAtBottom(st, item);
    st.push(temp);
}

void reverseStack(stack<int>& st) {
    if (st.empty()) return;
    int temp = st.top(); st.pop();
    reverseStack(st);
    insertAtBottom(st, temp);
}

int main() {
    stack<int> st;
    st.push(3); st.push(1); st.push(4); st.push(2);

    reverseStack(st);

    // print reversed stack
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}