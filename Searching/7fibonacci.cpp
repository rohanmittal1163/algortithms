#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
 * Fibonacci Search
 * Time          : Best O(1) | Avg O(log n) | Worst O(log n)
 * Space         : O(1)
 * Prerequisite  : Sorted data
 * Approach      : Iterative (split by Fibonacci numbers instead of halves)
 * Distribution  : No assumption
 * Note          : Uses only addition/subtraction (no division), and accesses nearby
 *                 elements, which helps on hardware where far jumps are costly
 */
int fibonacciSearch(const vector<int> &a, int key)
{
    int n = a.size();
    int fib2 = 0;        // (m-2)th Fibonacci number
    int fib1 = 1;        // (m-1)th Fibonacci number
    int fib = fib2 + fib1; // mth Fibonacci number

    while (fib < n)
    {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    int offset = -1; // range eliminated from the front
    while (fib > 1)
    {
        int i = min(offset + fib2, n - 1);
        if (a[i] < key)
        {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if (a[i] > key)
        {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else
            return i;
    }
    if (fib1 && offset + 1 < n && a[offset + 1] == key)
        return offset + 1;
    return -1;
}

int main()
{
    vector<int> a = {10, 22, 35, 40, 45, 50, 80, 82, 85, 90, 100};
    cout << fibonacciSearch(a, 85) << endl;
    cout << fibonacciSearch(a, 10) << endl;
    cout << fibonacciSearch(a, 100) << endl;
    cout << fibonacciSearch(a, 60) << endl;
    return 0;
}
