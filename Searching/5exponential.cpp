#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Exponential Search
 * Time          : Best O(1) | Avg O(log i) | Worst O(log n), i = index of the key
 * Space         : O(1) with iterative binary search | O(log n) with recursive
 * Prerequisite  : Sorted data
 * Approach      : Double the bound (1, 2, 4, ...) to find a range, then binary search inside it
 * Distribution  : No assumption; best for unbounded/infinite arrays or when the key is near the start
 */
int binarySearch(const vector<int> &a, int lo, int hi, int key)
{
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] < key)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

int exponentialSearch(const vector<int> &a, int key)
{
    int n = a.size();
    if (n == 0)
        return -1;
    if (a[0] == key)
        return 0;
    int i = 1;
    while (i < n && a[i] <= key)
        i *= 2;
    return binarySearch(a, i / 2, min(i, n - 1), key);
}

int main()
{
    vector<int> a = {2, 3, 4, 10, 40, 50, 60, 70, 80, 90};
    cout << exponentialSearch(a, 10) << endl;
    cout << exponentialSearch(a, 90) << endl;
    cout << exponentialSearch(a, 5) << endl;
    return 0;
}
