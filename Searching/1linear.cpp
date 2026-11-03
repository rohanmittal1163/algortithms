#include <iostream>
#include <vector>
using namespace std;

/*
 * Linear Search
 * Time          : Best O(1) (first element) | Avg O(n) | Worst O(n)
 * Space         : O(1) iterative | O(n) recursive (call stack)
 * Prerequisite  : None, works on unsorted data
 * Approach      : Iterative and recursive both shown
 * Distribution  : No assumption
 */
int linearSearch(const vector<int> &a, int key)
{
    for (int i = 0; i < (int)a.size(); i++)
    {
        if (a[i] == key)
            return i;
    }
    return -1;
}

int linearSearchRec(const vector<int> &a, int key, int i = 0)
{
    if (i >= (int)a.size())
        return -1;
    if (a[i] == key)
        return i;
    return linearSearchRec(a, key, i + 1);
}

int main()
{
    vector<int> a = {64, 34, 25, 12, 22, 11, 90};
    cout << linearSearch(a, 22) << endl;
    cout << linearSearchRec(a, 90) << endl;
    cout << linearSearch(a, 100) << endl;
    return 0;
}
