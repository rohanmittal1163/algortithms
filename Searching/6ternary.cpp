#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
 * Ternary Search
 * Time          : Best O(1) | Avg O(log3 n) | Worst O(log3 n)
 *                 (log3 n is still O(log n); it makes ~2 comparisons per step, so it is
 *                  slower than binary search for plain lookup)
 * Space         : O(1) iterative | O(log3 n) recursive (call stack)
 * Prerequisite  : Sorted data for lookup | Unimodal function for finding a max/min
 * Approach      : Iterative and recursive both shown
 * Distribution  : No assumption; the function must strictly rise then fall (or the reverse)
 */

// Lookup in a sorted array: split into 3 parts with two midpoints
int ternarySearch(const vector<int> &a, int key)
{
    int lo = 0, hi = a.size() - 1;
    while (lo <= hi)
    {
        int third = (hi - lo) / 3;
        int m1 = lo + third;
        int m2 = hi - third;
        if (a[m1] == key)
            return m1;
        if (a[m2] == key)
            return m2;
        if (key < a[m1])
            hi = m1 - 1;
        else if (key > a[m2])
            lo = m2 + 1;
        else
        {
            lo = m1 + 1;
            hi = m2 - 1;
        }
    }
    return -1;
}

int ternarySearchRec(const vector<int> &a, int lo, int hi, int key)
{
    if (lo > hi)
        return -1;
    int third = (hi - lo) / 3;
    int m1 = lo + third;
    int m2 = hi - third;
    if (a[m1] == key)
        return m1;
    if (a[m2] == key)
        return m2;
    if (key < a[m1])
        return ternarySearchRec(a, lo, m1 - 1, key);
    if (key > a[m2])
        return ternarySearchRec(a, m2 + 1, hi, key);
    return ternarySearchRec(a, m1 + 1, m2 - 1, key);
}

// Maximum of a unimodal function on [lo, hi]
double f(double x)
{
    return -(x - 3) * (x - 3) + 5; // peak at x = 3
}

double ternaryMax(double lo, double hi)
{
    for (int i = 0; i < 100; i++)
    {
        double m1 = lo + (hi - lo) / 3;
        double m2 = hi - (hi - lo) / 3;
        if (f(m1) < f(m2))
            lo = m1;
        else
            hi = m2;
    }
    return (lo + hi) / 2;
}

int main()
{
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << ternarySearch(a, 5) << endl;
    cout << ternarySearchRec(a, 0, a.size() - 1, 10) << endl;
    cout << ternarySearch(a, 11) << endl;
    cout << ternaryMax(-10, 10) << endl;
    return 0;
}
