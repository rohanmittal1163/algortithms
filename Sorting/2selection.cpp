#include <iostream>
#include <vector>
using namespace std;

/*
 * Selection Sort
 * Time     : Best O(n^2) | Avg O(n^2) | Worst O(n^2)  (always scans the rest of the array)
 * Space    : O(1)
 * In-place : Yes
 * Stable   : No (the long-distance swap can reorder equal elements)
 * Adaptive : No (same number of comparisons regardless of input order)
 */
void selectionSort(vector<int> &a) {
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx]) minIdx = j;
        }
        if (minIdx != i) swap(a[i], a[minIdx]);
    }
}

int main() {
    vector<int> a = {64, 25, 12, 22, 11};
    selectionSort(a);
    for (int x : a) cout << x << " ";
    cout << endl;
    return 0;
}
