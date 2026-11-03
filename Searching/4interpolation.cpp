#include <iostream>
#include <vector>
using namespace std;

/*
 * Interpolation Search
 * Time          : Best O(1) | Avg O(log log n) (uniform data) | Worst O(n) (skewed data)
 * Space         : O(1) iterative | O(log log n) to O(n) recursive (call stack)
 * Prerequisite  : Sorted data
 * Approach      : Iterative and recursive both shown
 * Distribution  : Assumes uniformly distributed values; degrades on exponential/skewed data
 */
int interpolationSearch(const vector<int> &a, int key)
{
    int lo = 0, hi = a.size() - 1;
    while (lo <= hi && key >= a[lo] && key <= a[hi])
    {
        if (a[hi] == a[lo])
            return a[lo] == key ? lo : -1;
        int pos = lo + (long long)(key - a[lo]) * (hi - lo) / (a[hi] - a[lo]);
        if (a[pos] == key)
            return pos;
        if (a[pos] < key)
            lo = pos + 1;
        else
            hi = pos - 1;
    }
    return -1;
}

int interpolationSearchRec(const vector<int> &a, int lo, int hi, int key)
{
    if (lo > hi || key < a[lo] || key > a[hi])
        return -1;
    if (a[hi] == a[lo])
        return a[lo] == key ? lo : -1;
    int pos = lo + (long long)(key - a[lo]) * (hi - lo) / (a[hi] - a[lo]);
    if (a[pos] == key)
        return pos;
    if (a[pos] < key)
        return interpolationSearchRec(a, pos + 1, hi, key);
    return interpolationSearchRec(a, lo, pos - 1, key);
}

int main()
{
    vector<int> a = {10, 12, 13, 16, 18, 19, 20, 21, 22, 23, 24, 33, 35, 42, 47};
    cout << interpolationSearch(a, 18) << endl;
    cout << interpolationSearchRec(a, 0, a.size() - 1, 47) << endl;
    cout << interpolationSearch(a, 25) << endl;
    return 0;
}
