#include <bits/stdc++.h>
using namespace std;

// concept of 2*idx+1 2*idx+2;
// concept of size of segment tree of 4*n
//

// questions
// Xenia and bit operations
// length of the maximum correct bracket subsequence  => stack TLE , segment tree
// *** inversion of array => BIT / segment (for negative element sometimes fails and complex) (range sum)

class SGTree
{
private:
    vector<int> seg;
    vector<int> lazy;
    vector<int> arr;
    int n;

public:
    SGTree(const vector<int> &arr)
    {
        this->arr = arr;
        this->n = arr.size();
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }
    void build(int idx, int low, int high)
    {
        // O(n)
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(2 * idx + 1, low, mid);
        build(2 * idx + 2, mid + 1, high);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
    int query(int idx, int l, int r, int low, int high)
    {
        // O(logn)
        // l r low high || low high l r
        if (r < low || l > high)
        {
            return INT_MAX;
        }
        // [l low high r]
        if (low >= l && high <= r)
        {
            return seg[idx];
        }
        int mid = (low + high) >> 1;
        int left = query(2 * idx + 1, l, r, low, mid);
        int right = query(2 * idx + 2, l, r, mid + 1, high);
        return min(left, right);
    }
    // point updates

    void update(int idx, int low, int high, int i, int val, vector<int> arr)
    {
        // O(logN)
        if (low == high)
        {
            seg[idx] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if (i <= mid)
        {
            update(2 * idx + 1, low, mid, i, val, arr);
        }
        else
        {
            update(2 * idx + 2, mid + 1, high, i, val, arr);
        }
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    // lazy propagation -> range update -> sum
    void rangeUpdate(int ind, int low, int high, int l, int r, int val)
    {
        if (lazy[ind] != 0)
        {
            seg[ind] += (high - low + 1) * lazy[ind];
            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        // no overlap

        if (r < low || high < l)
        {
            return;
        }

        // overlap
        if (l <= low && high <= r)
        {
            seg[ind] = (high - low + 1) * val;
            if (low != high)
            {
                lazy[2 * ind + 1] += val;
                lazy[2 * ind + 2] += val;
            }
            return;
        }
        int mid = (low + high) >> 1;
        rangeUpdate(2 * ind + 1, low, mid, l, r, val);
        rangeUpdate(2 * ind + 2, mid + 1, high, l, r, val);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind] + 2;
    }
    int query(int ind, int low, int high, int l, int r)
    {
        // lazy propogation only add this
        if (lazy[ind] != 0)
        {
            lazy[ind] = (high - low + 1) * lazy[ind];
            if (low != high)
            {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        if (r < low || high < l)
        {
            return 0;
        }

        if (l <= low && high <= r)
        {
            return seg[ind];
        }
        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);
        return left + right;
    }
    // after this think of range min
    // head and tail question flipping in a range
};

int main()
{
    return 0;
}
