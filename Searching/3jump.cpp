#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

/*
 * Jump Search
 * Time          : Best O(1) | Avg O(sqrt(n)) | Worst O(sqrt(n))
 * Space         : O(1)
 * Prerequisite  : Sorted data
 * Approach      : Iterative (jump in blocks of sqrt(n), then linear scan inside the block)
 * Distribution  : No assumption
 * Note          : Only moves forward, so it is useful when going backward is costly
 */
int jumpSearch(const vector<int> &a, int key)
{
    int n = a.size();
    if (n == 0)
        return -1;
    int step = sqrt(n);
    int prev = 0;
    while (a[min(step, n) - 1] < key)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
            return -1;
    }
    for (int i = prev; i < min(step, n); i++)
    {
        if (a[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    vector<int> a = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610};
    cout << jumpSearch(a, 55) << endl;
    cout << jumpSearch(a, 610) << endl;
    cout << jumpSearch(a, 4) << endl;
    return 0;
}
