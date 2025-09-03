#include <iostream>
#include <stack>
using namespace std;

// Function to insert element in sorted stack
void insertSorted(stack<int>& st, int element) {
    // If stack is empty OR top element <= current element
    if (st.empty() || st.top() <= element) {
        st.push(element);
        return;
    }

    // Otherwise remove the top and recurse
    int temp = st.top();
    st.pop();
    insertSorted(st, element);

    // Push back the removed element
    st.push(temp);
}

// Function to sort stack recursively
void sortStack(stack<int>& st) {
    if (!st.empty()) {
        int temp = st.top();
        st.pop();

        // Sort remaining stack
        sortStack(st);

        // Insert the popped element in correct position
        insertSorted(st, temp);
    }
}

// Utility function to print stack (top to bottom)
void printStack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

int main() {
    stack<int> st;

    // Input: [3, 1, 4, 2]
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    cout << "Original Stack (top to bottom): ";
    printStack(st);

    // Need to reconstruct because printStack empties it
    st.push(3);
    st.push(1);
    st.push(4);
    st.push(2);

    // Sort
    sortStack(st);

    cout << "Sorted Stack (top to bottom): ";
    printStack(st);

    return 0;
}