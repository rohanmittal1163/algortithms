#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Counting Sort (non-negative integers)
 * Time     : Best/Avg/Worst O(n + k), k = max value
 * Space    : O(n + k) (count array + output array)
 * In-place : No
 * Stable   : Yes (output filled from the back using prefix sums)
 * Adaptive : No (always O(n + k) regardless of order)
 */
void countingSort(vector<int> &a)
{
    if (a.empty())
        return;
    int k = *max_element(a.begin(), a.end());
    vector<int> count(k + 1, 0), output(a.size());
    for (int x : a)
        count[x]++;
    for (int i = 1; i <= k; i++)
        count[i] += count[i - 1];
    for (int i = a.size() - 1; i >= 0; i--)
    {
        output[--count[a[i]]] = a[i];
    }
    a = output;
}

int main()
{
    vector<int> a = {4, 2, 2, 8, 3, 3, 1};
    countingSort(a);
    for (int x : a)
        cout << x << " ";
    cout << endl;
    return 0;
}
