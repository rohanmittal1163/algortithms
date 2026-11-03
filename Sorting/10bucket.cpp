#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Bucket Sort (floats uniformly distributed in [0, 1))
 * Time     : Best O(n + k) | Avg O(n + k) (uniform input) | Worst O(n^2) (all elements in one bucket)
 * Space    : O(n + k), k = number of buckets
 * In-place : No
 * Stable   : Yes (if the per-bucket sort is stable; insertion sort here is)
 * Adaptive : Partly (insertion sort inside buckets is fast on nearly sorted buckets,
 *            but the overall algorithm depends on distribution, not input order)
 */
void insertionSort(vector<float> &b) {
    for (int i = 1; i < (int)b.size(); i++) {
        float key = b[i];
        int j = i - 1;
        while (j >= 0 && b[j] > key) {
            b[j + 1] = b[j];
            j--;
        }
        b[j + 1] = key;
    }
}

void bucketSort(vector<float> &a) {
    int n = a.size();
    if (n == 0) return;
    vector<vector<float>> buckets(n);
    for (float x : a) buckets[(int)(n * x)].push_back(x);
    for (auto &b : buckets) insertionSort(b);
    int idx = 0;
    for (auto &b : buckets)
        for (float x : b) a[idx++] = x;
}

int main() {
    vector<float> a = {0.897f, 0.565f, 0.656f, 0.1234f, 0.665f, 0.3434f};
    bucketSort(a);
    for (float x : a) cout << x << " ";
    cout << endl;
    return 0;
}
