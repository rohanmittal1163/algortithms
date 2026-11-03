#include <iostream>
#include <vector>
using namespace std;

/*
 * Binary Search
 * Time          : Best O(1) (middle element) | Avg O(log n) | Worst O(log n)
 * Space         : O(1) iterative | O(log n) recursive (call stack)
 * Prerequisite  : Sorted data
 * Approach      : Iterative and recursive both shown
 * Distribution  : No assumption (only needs random access + sorted order)
 */
int binarySearch(const vector<int> &a, int key)
{
    int lo = 0, hi = a.size() - 1;
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

int binarySearchRec(const vector<int> &a, int lo, int hi, int key)
{
    if (lo > hi)
        return -1;
    int mid = lo + (hi - lo) / 2;
    if (a[mid] == key)
        return mid;
    if (a[mid] < key)
        return binarySearchRec(a, mid + 1, hi, key);
    return binarySearchRec(a, lo, mid - 1, key);
}

int main()
{
    vector<int> a = {2, 3, 4, 10, 40, 50, 70};
    cout << binarySearch(a, 10) << endl;
    cout << binarySearchRec(a, 0, a.size() - 1, 70) << endl;
    cout << binarySearch(a, 5) << endl;
    return 0;
}
