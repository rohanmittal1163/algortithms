#include <vector>
using namespace std;

class FenwickTree
{
private:
    int n;
    vector<int> bit; // Binary Indexed Tree

public:
    // Constructor: initialize BIT with given size
    FenwickTree(int size)
    {
        n = size;
        bit.assign(n + 1, 0); // 1-based indexing
    }

    // Point update: add `delta` to element at `index`
    void update(int index, int delta)
    {
        while (index <= n)
        {
            bit[index] += delta;
            index += index & -index; // Move to parent
        }
    }

    // Query prefix sum from index 1 to `index`
    int query(int index)
    {
        int sum = 0;
        while (index > 0)
        {
            sum += bit[index];
            index -= index & -index; // Move to ancestor
        }
        return sum;
    }

    // Query sum in range [l, r]
    int rangeQuery(int l, int r)
    {
        return query(r) - query(l - 1);
    }

    // Range update: add delta to range [l, r]
    void rangeUpdate(int l, int r, int delta)
    {
        update(l, delta);
        update(r + 1, -delta);
    }
};
