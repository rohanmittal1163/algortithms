#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Radix Sort (LSD, base 10, non-negative integers)
 * Time     : Best/Avg/Worst O(d * (n + b)), d = number of digits, b = base (10)
 * Space    : O(n + b)
 * In-place : No
 * Stable   : Yes (relies on a stable counting sort per digit; stability is required for correctness)
 * Adaptive : No (does all d passes regardless of order)
 */
void countByDigit(vector<int> &a, int exp) {
    int n = a.size();
    vector<int> output(n), count(10, 0);
    for (int x : a) count[(x / exp) % 10]++;
    for (int i = 1; i < 10; i++) count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[--count[(a[i] / exp) % 10]] = a[i];
    }
    a = output;
}

void radixSort(vector<int> &a) {
    if (a.empty()) return;
    int mx = *max_element(a.begin(), a.end());
    for (int exp = 1; mx / exp > 0; exp *= 10) countByDigit(a, exp);
}

int main() {
    vector<int> a = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(a);
    for (int x : a) cout << x << " ";
    cout << endl;
    return 0;
}
