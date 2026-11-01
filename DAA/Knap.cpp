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
/*
================================================================================
THEORETICAL CONCEPTS, HOW TO RUN & HOW TO EXPLAIN
================================================================================
1. THEORETICAL CONCEPTS:
   - Problem Statement: 0/1 Knapsack Problem — Given weights and values of n items,
     put items in a knapsack of capacity W to get maximum total value without breaking items.
   - Dynamic Programming (DP) Principle:
     * Overlapping Subproblems & Optimal Substructure.
     * Recurrence Relation:
       If weight[i-1] <= w:
         dp[i][w] = max(dp[i-1][w], dp[i-1][w - weight[i-1]] + value[i-1])
       Else:
         dp[i][w] = dp[i-1][w]
   - Time Complexity : O(n * W) (pseudo-polynomial, where n = number of items, W = capacity).
   - Space Complexity: O(n * W) for the 2D DP table.
   - Backtracking: Scans backwards from dp[n][W] to determine which specific items were included.

2. HOW TO RUN:
   - Compile: g++ Knap.cpp -o Knap
   - Run    : ./Knap        (Linux/macOS) or Knap.exe (Windows)

3. HOW TO EXPLAIN TO THE EXAMINER (30-SECOND VIVA PITCH):
   "Sir/Madam, this program solves the classic 0/1 Knapsack Problem using Dynamic Programming:
   - Unlike Fractional Knapsack (which is greedy and allows fractions), 0/1 Knapsack requires
     deciding whether to take an item completely (1) or leave it (0).
   - We construct an (n+1) x (W+1) table where dp[i][w] stores maximum value using a subset
     of first i items with weight limit w.
   - For every item, we take the maximum between excluding it (dp[i-1][w]) and including it
     (dp[i-1][w - weight] + value).
   - Finally, we backtrack through the table to print which items were selected.
   - Time and space complexities are both O(n * W)."

4. COMMON VIVA QUESTIONS:
   Q: Why can't we use a Greedy algorithm for 0/1 Knapsack?
   A: Greedy based on value-to-weight ratio fails for 0/1 knapsack because empty capacity
      cannot be filled with fractions of items, leaving suboptimal wasted space.
   Q: Can space complexity be optimized?
   A: Yes, to O(W) using a 1D DP array traversed right-to-left.
================================================================================
*/
