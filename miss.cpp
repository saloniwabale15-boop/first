#include <iostream>
#include <vector>
using namespace std;

int findMissing(vector<int>& arr) {
    int n = arr.size() + 1;  // Total numbers should be n
    int totalSum = n * (n + 1) / 2;
    int arrSum = 0;

    for (int num : arr) {
        arrSum += num;
    }

    return totalSum - arrSum;
}

int main() {
    vector<int> arr = {1, 2, 4, 5};  // Example
    cout << "Missing number is: " << findMissing(arr) << endl;
    return 0;
}