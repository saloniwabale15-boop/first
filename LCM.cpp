#include <iostream>
using namespace std;

// Function to compute GCD
int gcd(int a, int b) {
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute LCM
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int N, M;
    cout << "Enter two numbers: ";
    cin >> N >> M;

    cout << "LCM of " << N << " and " << M << " is: " << lcm(N, M) << endl;
    return 0;
}