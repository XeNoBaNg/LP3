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
/*
================================================================================
THEORETICAL CONCEPTS, HOW TO RUN & HOW TO EXPLAIN
================================================================================
1. THEORETICAL CONCEPTS:
   - Problem Statement: Place N non-attacking queens on an N x N chessboard such that
     no two queens share the same row, column, or diagonal.
   - Backtracking Strategy:
     * A systematic search of the solution space. If a partial placement violates safety,
       the algorithm backtracks (undoes placement) immediately, pruning infeasible branches.
   - Pre-Placed First Queen:
     * The 1st queen is manually placed at user-specified (ROW, COL).
     * The solver skips COL and places queens in columns 0 to N-1 recursively.
   - Safety Condition (isSafe):
     * Same row: i == row
     * Same diagonal: |i - row| == |j - col|
   - Time Complexity : O(N!) in worst-case backtracking.
   - Space Complexity: O(N^2) for the board representation + O(N) recursion call stack.

2. HOW TO RUN:
   - Compile: g++ nq.cpp -o nq
   - Run    : ./nq          (Linux/macOS) or nq.exe (Windows)
   - Input  : Enter board size N (e.g., 4 or 8), then row and col of 1st queen (e.g., 1 1).

3. HOW TO EXPLAIN TO THE EXAMINER (30-SECOND VIVA PITCH):
   "Sir/Madam, this program implements the N-Queens problem using Backtracking with the 1st queen pre-placed:
   - The user inputs board size N and coordinates for the first queen.
   - We place queens column by column. For each column, we check rows 0 to N-1 using isSafe().
   - isSafe() ensures no conflict on the same row or diagonals using |row1 - row2| == |col1 - col2|.
   - If placing a queen leads to a valid solution, we continue; otherwise, we backtrack by setting
     board[row][col] = 0 and try the next row.
   - Time complexity is O(N!) and space complexity is O(N^2)."

4. COMMON VIVA QUESTIONS:
   Q: What is Backtracking?
   A: It is an algorithmic technique for solving problems recursively by trying to build a
      solution incrementally, one piece at a time, removing those that fail to satisfy constraints.
   Q: For which values of N does N-Queens have NO solution?
   A: N = 2 and N = 3 have no solutions. Solutions exist for all N >= 4 (and N = 1).
================================================================================
*/
