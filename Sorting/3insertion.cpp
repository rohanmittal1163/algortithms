#include <iostream>
#include <vector>
using namespace std;

/*
 * Insertion Sort
 * Time     : Best O(n) (already sorted) | Avg O(n^2) | Worst O(n^2) (reverse sorted)
 * Space    : O(1)
 * In-place : Yes
 * Stable   : Yes (shifts only while a[j] > key)
 * Adaptive : Yes (runs in O(n + inversions))
 */
void insertionSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

int main()
{
    vector<int> a = {12, 11, 13, 5, 6};
    insertionSort(a);
    for (int x : a)
        cout << x << " ";
    cout << endl;
    return 0;
}