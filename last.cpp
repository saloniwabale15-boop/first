#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    // Initialize dp array with a large value (amount+1 means unreachable)
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;  // base case: 0 coins needed for amount 0

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
    }

    return (dp[amount] == amount + 1) ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = coinChange(coins, amount);
    cout << "Minimum coins required: " << result << endl;

    return 0;
}