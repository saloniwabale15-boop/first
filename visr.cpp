#include <bits/stdc++.h>
using namespace std;

vector<int> slidingWindowMaximum(vector<int>& arr, int k) {
    deque<int> dq;          // stores indices of elements
    vector<int> result;

    for (int i = 0; i < arr.size(); i++) {
        // Remove indices that are out of this window
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Remove all elements smaller than current from the back
        while (!dq.empty() && arr[dq.back()] < arr[i])
            dq.pop_back();

        dq.push_back(i);

        // Once we have a window of size k, record the max
        if (i >= k - 1)
            result.push_back(arr[dq.front()]);
    }
    return result;
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    vector<int> ans = slidingWindowMaximum(arr, k);

    cout << "[ ";
    for (int x : ans) cout << x << " ";
    cout << "]\n";

    return 0;
}