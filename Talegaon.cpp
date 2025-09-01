#include <iostream>
#include <cmath>
using namespace std;

int countDivisors(int n) {
    int count = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (i == n / i)
                count++;  // Perfect square
            else
                count += 2; // i and n/i
        }
    }
    return count;
}

int main() {
    int N;
    cout << "Enter a number: ";
    cin >> N;
    cout << "Number of divisors: " << countDivisors(N) << endl;
    return 0;
}