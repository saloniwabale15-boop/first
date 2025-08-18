#include <bits/stdc++.h>
using namespace std;

void mergeArrays(vector<int>& arr1, vector<int>& arr2) {
    int m = arr1.size();
    int n = arr2.size();

    int i = m - 1;
    int j = 0;

    // Swap elements if out of order
    while (i >= 0 && j < n) {
        if (arr1[i] > arr2[j]) {
            swap(arr1[i], arr2[j]);
        }
        i--;
        j++;
    }

    // Re-sort both arrays
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};

    mergeArrays(arr1, arr2);

    cout << "arr1 = ";
    for (int x : arr1) cout << x << " ";
    cout << "\n";

    cout << "arr2 = ";
    for (int x : arr2) cout << x << " ";
    cout << "\n";

    return 0;
}
