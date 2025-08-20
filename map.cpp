#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> findZeroSumSubarrays(vector<int>& arr) {
    vector<pair<int, int>> result;
    unordered_map<int, vector<int>> prefixMap; 
    int prefixSum = 0;

    // Initialize with prefixSum 0 at index -1
    prefixMap[0].push_back(-1);

    for (int i = 0; i < arr.size(); i++) {
        prefixSum += arr[i];

        if (prefixMap.find(prefixSum) != prefixMap.end()) {
            for (int startIndex : prefixMap[prefixSum]) {
                result.push_back({startIndex + 1, i});
            }
        }
        prefixMap[prefixSum].push_back(i);
    }
    return result;
}

int main() {
    vector<int> arr = {1, 2, -3, 3, -1, 2};
    vector<pair<int, int>> subarrays = findZeroSumSubarrays(arr);

    cout << "[";
    for (int i = 0; i < subarrays.size(); i++) {
        cout << "(" << subarrays[i].first << ", " << subarrays[i].second << ")";
        if (i != subarrays.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}