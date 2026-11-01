#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// N-Queens using Backtracking (with 1st Queen pre-placed)
// Time Complexity : O(N!)
// Space Complexity: O(N^2) for board + O(N) recursion stack

int N, ROW, COL;

void printSolution(const vector<vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << "\n";
    }
}

// Check if placing a queen at (row, col) conflicts with any placed queen
bool isSafe(const vector<vector<int>>& board, int row, int col) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // Same row or same diagonal (|Δrow| == |Δcol|)
            if (board[i][j] && (i == row || abs(i - row) == abs(j - col)))
                return false;
        }
    }
    return true;
}

// Backtracking solver column by column
bool solveNQUtil(vector<vector<int>>& board, int col) {
    if (col >= N)
        return true;

    // Skip the column where the 1st queen is already pre-placed
    if (col == COL)
        return solveNQUtil(board, col + 1);

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;

            if (solveNQUtil(board, col + 1))
                return true;

            board[i][col] = 0; // Backtrack
        }
    }
    return false;
}

int main() {
    cout << "Enter size of board: ";
    cin >> N;
    cout << "Enter row and col of first queen to be placed:\n";
    cout << "row (1-" << N << "): ";
    cin >> ROW;
    cout << "col (1-" << N << "): ";
    cin >> COL;
    cout << "\n";

    ROW--; COL--; // Convert to 0-based indexing

    if (ROW < 0 || ROW >= N || COL < 0 || COL >= N) {
        cout << "Invalid coordinates! Must be between 1 and " << N << ".\n";
        return 0;
    }

    vector<vector<int>> board(N, vector<int>(N, 0));
    board[ROW][COL] = 1; // Place 1st queen

    if (!solveNQUtil(board, 0)) {
        cout << "Solution does not exist\n";
    } else {
        printSolution(board);
    }

    return 0;
}