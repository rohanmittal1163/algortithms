#include <iostream>
#include <vector>
using namespace std;

/*
 * Merge Sort
 * Time     : Best O(n log n) | Avg O(n log n) | Worst O(n log n)
 * Space    : O(n) auxiliary (temp arrays used while merging)
 * In-place : No
 * Stable   : Yes (take from the left half on ties: <=)
 * Adaptive : No (always splits and merges the same way)
 */
void merge(vector<int> &a, int l, int m, int r)
{
    vector<int> left(a.begin() + l, a.begin() + m + 1);
    vector<int> right(a.begin() + m + 1, a.begin() + r + 1);
    int i = 0, j = 0, k = l;
    while (i < (int)left.size() && j < (int)right.size())
    {
        if (left[i] <= right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }
    while (i < (int)left.size())
        a[k++] = left[i++];
    while (j < (int)right.size())
        a[k++] = right[j++];
}

void mergeSort(vector<int> &a, int l, int r)
{
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

int main()
{
    vector<int> a = {38, 27, 43, 3, 9, 82, 10};
    mergeSort(a, 0, a.size() - 1);
    for (int x : a)
        cout << x << " ";
    cout << endl;
    return 0;
}