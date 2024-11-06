#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(vector<int>& weights, vector<int>& values, int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the dp table in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weights[i - 1] <= w)
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Store the result of Knapsack
    int result = dp[n][capacity];

    // Find the items that were included in the knapsack
    cout << "Selected items:" << endl;
    int w = capacity;
    for (int i = n; i > 0 && result > 0; i--) {
        if (result != dp[i - 1][w]) {
            cout << "Item " << i << " (Weight: " << weights[i - 1] << ", Value: " << values[i - 1] << ")" << endl;
            result -= values[i - 1];
            w -= weights[i - 1];
        }
    }

    // Return the maximum value we can get
    return dp[n][capacity];
}

int main() {
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int capacity = 50;

    int maxValue = knapsack(weights, values, capacity);
    cout << "Maximum value: " << maxValue << endl;

    return 0;
}

