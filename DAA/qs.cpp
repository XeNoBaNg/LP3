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