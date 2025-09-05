#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int firstToRepeatKTimes(const vector<int>& arr, int k) {
    unordered_map<int, int> freq;

    // Count frequencies
    for (int num : arr) {
        freq[num]++;
    }

    // Find first element with exactly k occurrences
    for (int num : arr) {
        if (freq[num] == k) {
            return num;
        }
    }
    return -1; // no element found
}

int main() {
    vector<int> arr = {3, 1, 4, 4, 5, 2, 6, 1, 4};
    int k = 2;

    int result = firstToRepeatKTimes(arr, k);
    cout << result << endl;  // Output: 1

    return 0;
}