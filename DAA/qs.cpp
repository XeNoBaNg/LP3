#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Deterministic & Randomized Quick Sort
// Time Complexity:
//   - Average: O(n log n)
//   - Worst (Deterministic): O(n^2) (e.g., already sorted array)
//   - Worst (Randomized): O(n^2) (negligible probability)
// Space Complexity: O(log n) recursion call stack

// Standard partition using first element as pivot
int partition(vector<int>& arr, int low, int high, int& comps, int& swaps) {
    int pivot = arr[low];
    int i = low;

    for (int j = low + 1; j <= high; j++) {
        comps++;
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
            swaps++;
        }
    }
    swap(arr[low], arr[i]);
    swaps++;
    return i;
}

// Randomized partition: swap random element with first, then reuse partition
int randomizedPartition(vector<int>& arr, int low, int high, int& comps, int& swaps) {
    int randIdx = low + rand() % (high - low + 1);
    swap(arr[low], arr[randIdx]);
    swaps++;
    return partition(arr, low, high, comps, swaps);
}

// Deterministic Quick Sort
void deterministicQuickSort(vector<int>& arr, int low, int high, int& comps, int& swaps) {
    if (low < high) {
        int p = partition(arr, low, high, comps, swaps);
        deterministicQuickSort(arr, low, p - 1, comps, swaps);
        deterministicQuickSort(arr, p + 1, high, comps, swaps);
    }
}

// Randomized Quick Sort
void randomizedQuickSort(vector<int>& arr, int low, int high, int& comps, int& swaps) {
    if (low < high) {
        int p = randomizedPartition(arr, low, high, comps, swaps);
        randomizedQuickSort(arr, low, p - 1, comps, swaps);
        randomizedQuickSort(arr, p + 1, high, comps, swaps);
    }
}

void printArray(const vector<int>& arr) {
    for (int x : arr) cout << x << " ";
    cout << "\n";
}

int main() {
    srand(time(0));
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> original(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> original[i];

    int choice;
    do {
        cout << "\n========== QUICK SORT MENU ==========\n";
        cout << "1. Deterministic Quick Sort\n";
        cout << "2. Randomized Quick Sort\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2) {
            vector<int> arr = original; // Keep original intact
            int comps = 0, swaps = 0;

            cout << "\nOriginal Array: ";
            printArray(arr);

            if (choice == 1) {
                deterministicQuickSort(arr, 0, n - 1, comps, swaps);
                cout << "Sorted Array (Deterministic): ";
            } else {
                randomizedQuickSort(arr, 0, n - 1, comps, swaps);
                cout << "Sorted Array (Randomized): ";
            }

            printArray(arr);
            cout << "Comparisons : " << comps << "\n";
            cout << "Swaps       : " << swaps << "\n";
        } else if (choice == 3) {
            cout << "Exiting program.\n";
        } else {
            cout << "Invalid choice! Enter 1, 2, or 3.\n";
        }
    } while (choice != 3);

    return 0;
}
/*
================================================================================
THEORETICAL CONCEPTS, HOW TO RUN & HOW TO EXPLAIN
================================================================================
1. THEORETICAL CONCEPTS:
   - Divide-and-Conquer Algorithm:
     1. Pick a pivot element.
     2. Partition the array so all elements < pivot are to the left, and > pivot to the right.
     3. Recursively sort the left and right subarrays.
   - Deterministic Quick Sort:
     * Uses a fixed pivot (e.g., arr[low] - first element).
     * Worst-case occurs on already sorted or reverse-sorted input: O(n^2).
     * Average-case: O(n log n).
   - Randomized Quick Sort:
     * Randomly picks an index between low and high, swaps with arr[low], then partitions.
     * Prevents adversarial inputs from triggering the O(n^2) worst case.
     * Expected running time is O(n log n) with extremely high probability.
   - Space Complexity: O(log n) auxiliary stack space for recursion.

2. HOW TO RUN:
   - Compile: g++ qs.cpp -o qs
   - Run    : ./qs          (Linux/macOS) or qs.exe (Windows)
   - Menu   : Choose 1 for Deterministic, 2 for Randomized, 3 to Exit.
   - Displays sorted output alongside comparison counts and swap counts!

3. HOW TO EXPLAIN TO THE EXAMINER (30-SECOND VIVA PITCH):
   "Sir/Madam, this program demonstrates Deterministic vs Randomized Quick Sort with step analysis:
   - Both follow the Divide-and-Conquer paradigm.
   - In deterministic quicksort, choosing the first element as pivot gives O(n^2) worst-case
     time on sorted inputs because partitions become highly unbalanced (size 1 and n-1).
   - In randomized quicksort, selecting a random pivot ensures balanced expected partitions,
     yielding O(n log n) average performance regardless of the initial input order.
   - We track and print total comparisons and swaps to empirically prove the efficiency."

4. COMMON VIVA QUESTIONS:
   Q: Why is Quick Sort preferred over Merge Sort for arrays?
   A: Quick Sort is in-place (O(log n) auxiliary space vs O(n) for Merge Sort) and exhibits
      excellent cache locality in virtual memory.
   Q: What is the recurrence relation for average case?
   A: T(n) = 2*T(n/2) + O(n), which resolves to O(n log n) by Master's Theorem.
================================================================================
*/
