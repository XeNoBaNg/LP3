#include <iostream>
using namespace std;

int fibonacci(int n) {
  if (n <= 1)
    return n;

  return fibonacci(n - 1) + fibonacci(n - 2);
}

/**
 * Time Complexity: O(2^n)
 * For each call fibonacci(n), it recursively calls fibonacci(n-1) and
 * fibonacci(n-2). This creates a tree of recursive calls where each node
 * represents a function call. The size of this recursive call tree is
 * exponential, and the time complexity is O(2^n) because for each n, you
 * essentially have two branches (n-1 and n-2).
 *
 * Space Complexity: O(n)
 * The recursion depth is proportional to n because it will reach the base case
 * after n recursive calls. Since there is no extra memory allocated except for
 * the recursive call stack, the space complexity is linear.
 */
void recursive(int n) {
  for (int i = 0; i < n; ++i)
    cout << fibonacci(i) << " ";
}

/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
void iterative(int n) {
  int a1 = 0;
  int a2 = 1;

  cout << a1 << " " << a2 << " ";

  for (int i = 2; i < n; i++) {
    int a3 = a2 + a1;
    a1 = a2;
    a2 = a3;
    cout << a2 << " ";
  }

  cout << endl;
}

int main() {
  recursive(10);
  cout << endl;
  iterative(10);
  return 0;
}
/*
================================================================================
THEORETICAL CONCEPTS, HOW TO RUN & HOW TO EXPLAIN
================================================================================
1. THEORETICAL CONCEPTS:
   - Fibonacci Sequence: F(0)=0, F(1)=1, F(n) = F(n-1) + F(n-2) for n >= 2.
   - Recursive Approach:
     * Divides problem into two subproblems: F(n-1) and F(n-2).
     * Solves overlapping subproblems repeatedly without memoization.
     * Time Complexity : O(2^n) - Exponential growth (branching factor of 2).
     * Space Complexity: O(n) - Maximum recursion call stack depth.
   - Non-Recursive (Iterative) Approach:
     * Uses dynamic bottom-up accumulation with two variables (a1, a2).
     * Computes each term exactly once.
     * Time Complexity : O(n) - Single linear loop.
     * Space Complexity: O(1) - Constant space, no call stack overhead.

2. HOW TO RUN:
   - Compile: g++ Fibo.cpp -o Fibo
   - Run    : ./Fibo        (Linux/macOS) or Fibo.exe (Windows)

3. HOW TO EXPLAIN TO THE EXAMINER (30-SECOND VIVA PITCH):
   "Sir/Madam, this program demonstrates the comparison between Recursive and Iterative
   strategies for generating Fibonacci numbers:
   - The recursive function fibonacci() follows a divide-and-conquer strategy, but due to
     repeatedly recalculating overlapping subproblems, its call tree grows exponentially as O(2^n),
     taking O(n) stack memory.
   - The iterative function iterative() calculates Fibonacci numbers bottom-up in a single
     loop from 2 to n using two temporary variables, cutting time complexity to O(n) and
     space complexity to O(1).
   - Hence, iteration or dynamic programming is far superior to naive recursion for large n."

4. COMMON VIVA QUESTIONS:
   Q: Why is recursive Fibonacci O(2^n)?
   A: Because each call creates 2 child calls, forming a binary recursion tree of depth n with ~2^n nodes.
   Q: How can recursive Fibonacci be optimized without loops?
   A: Using memoization (Top-Down Dynamic Programming) to cache previously computed results in O(n) time.
================================================================================
*/
