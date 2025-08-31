#include <iostream>
#include <vector>
using namespace std;

vector<int> primeFactorization(int n) {
    vector<int> factors;
    for (int divisor = 2; divisor * divisor <= n; divisor++) {
        while (n % divisor == 0) {
            factors.push_back(divisor);
            n /= divisor;
        }
    }
    if (n > 1) factors.push_back(n); // if n is prime
    return factors;
}

int main() {
    int N = 18;
    vector<int> result = primeFactorization(N);

    cout << "[ ";
    for (int x : result) cout << x << " ";
    cout << "]";
    return 0;
}