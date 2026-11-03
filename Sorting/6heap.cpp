#include <iostream>
#include <vector>
using namespace std;

/*
 * Heap Sort
 * Time     : Best O(n log n) | Avg O(n log n) | Worst O(n log n)
 * Space    : O(1) (iterative heapify)
 * In-place : Yes
 * Stable   : No (heap operations move equal elements across the array)
 * Adaptive : No (build-heap and extraction cost the same regardless of order)
 */
void heapify(vector<int> &a, int n, int i) {
    while (true) {
        int largest = i;
        int l = 2 * i + 1, r = 2 * i + 2;
        if (l < n && a[l] > a[largest]) largest = l;
        if (r < n && a[r] > a[largest]) largest = r;
        if (largest == i) break;
        swap(a[i], a[largest]);
        i = largest;
    }
}

void heapSort(vector<int> &a) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main() {
    vector<int> a = {12, 11, 13, 5, 6, 7};
    heapSort(a);
    for (int x : a) cout << x << " ";
    cout << endl;
    return 0;
}
