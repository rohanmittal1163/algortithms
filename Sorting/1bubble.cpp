#include <iostream>
#include <vector>
using namespace std;

/*
 * Bubble Sort
 * Time     : Best O(n) (already sorted, with early exit) | Avg O(n^2) | Worst O(n^2)
 * Space    : O(1)
 * In-place : Yes
 * Stable   : Yes (equal elements are never swapped)
 * Adaptive : Yes (early exit when a pass makes no swaps)
 */
void bubbleSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

int main()
{
    vector<int> a = {64, 34, 25, 12, 22, 11, 90};
    bubbleSort(a);
    for (int x : a)
        cout << x << " ";
    cout << endl;
    return 0;
}
