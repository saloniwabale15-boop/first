#include <iostream>
#include <vector>
using namespace std;

vector<int> findLeaders(vector<int>& arr) {
    int n = arr.size();
    vector<int> leaders;

    int max_from_right = arr[n-1];   // Rightmost element is always a leader
    leaders.push_back(max_from_right);

    // Traverse array from right to left
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > max_from_right) {
            leaders.push_back(arr[i]);
            max_from_right = arr[i];
        }
    }

    // Leaders are collected in reverse order, so reverse them
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main() {
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    
    vector<int> leaders = findLeaders(arr);

    cout << "Leaders: ";
    for (int x : leaders) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}