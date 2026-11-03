#include <iostream>
#include <vector>
using namespace std;

/*
 * Quick Sort (Lomuto partition, last element as pivot)
 * Time     : Best O(n log n) | Avg O(n log n) | Worst O(n^2) (sorted input with this pivot choice)
 * Space    : O(log n) average recursion stack, O(n) worst case
 * In-place : Yes (only the recursion stack is extra)
 * Stable   : No (partition swaps jump over equal elements)
 * Adaptive : No (this version does not benefit from presortedness; it actually degrades)
 */
int partition(vector<int> &a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(vector<int> &a, int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main() {
    vector<int> a = {10, 7, 8, 9, 1, 5};
    quickSort(a, 0, a.size() - 1);
    for (int x : a) cout << x << " ";
    cout << endl;
    return 0;
}
