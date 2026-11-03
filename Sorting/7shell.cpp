#include <iostream>
#include <vector>
using namespace std;

/*
 * Shell Sort (gap sequence: n/2, n/4, ..., 1)
 * Time     : Best O(n log n) | Avg depends on gaps (~O(n^1.5)) | Worst O(n^2) with this gap sequence
 * Space    : O(1)
 * In-place : Yes
 * Stable   : No (gapped insertion moves equal elements past each other)
 * Adaptive : Yes (fewer shifts on nearly sorted data)
 */
void shellSort(vector<int> &a) {
    int n = a.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = a[i];
            int j = i;
            while (j >= gap && a[j - gap] > temp) {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = temp;
        }
    }
}

int main() {
    vector<int> a = {12, 34, 54, 2, 3, 99, 1};
    shellSort(a);
    for (int x : a) cout << x << " ";
    cout << endl;
    return 0;
}
