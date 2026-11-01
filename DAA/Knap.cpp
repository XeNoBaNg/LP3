#include <iostream>
#include <vector>
using namespace std;

// 0/1 Knapsack using Dynamic Programming
// Time Complexity : O(n * W)
// Space Complexity: O(n * W)

struct Item {
    int weight;
    int value;
};

void knapsack(int W, vector<Item>& items) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (items[i - 1].weight <= w)
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - items[i - 1].weight] + items[i - 1].value);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    cout << "Maximum Value: " << dp[n][W] << "\n\n";

    // Backtrack to find selected items
    cout << "Selected Items (Weight, Value):\n";
    int res = dp[n][W];
    int w = W;
    for (int i = n; i > 0 && res > 0; i--) {
        if (res != dp[i - 1][w]) { // Item was included
            cout << "Item " << i << " -> Weight: " << items[i - 1].weight
                 << ", Value: " << items[i - 1].value << "\n";
            res -= items[i - 1].value;
            w -= items[i - 1].weight;
        }
    }
}

int main() {
    int W = 269; // Knapsack capacity
    vector<Item> items = {{95, 55}, {4, 10},  {60, 47}, {32, 5},
                          {23, 4},  {72, 50}, {80, 8},  {62, 61},
                          {65, 85}, {46, 87}}; // {weight, value}

    knapsack(W, items);

    return 0;
}