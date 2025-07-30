#include <bits/stdc++.h>
using namespace std;

class SGTree
{
private:
    vector<int> seg, lazy, arr;
    int n;

public:
    SGTree(const vector<int> &arr)
    {
        this->arr = arr;
        this->n = arr.size();
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }
    // Merge function (can be changed to min, max, etc.)
    int merge(int a, int b)
    {
        return a + b; // sum
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
        seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int query(int l, int r)
    {
        return queryUtil(0, 0, n - 1, l, r);
    }

    int queryUtil(int idx, int start, int end, int l, int r)
    {
        // O(logn)
        if (r < start || end < l)
            return 0; // No overlap // return INT_MIN,INT_MAX,0

        if (l <= start && end <= r)
            return seg[idx]; // Total overlap

        int mid = (start + end) / 2;
        int leftSum = queryUtil(2 * idx + 1, start, mid, l, r);
        int rightSum = queryUtil(2 * idx + 2, mid + 1, end, l, r);
        return merge(leftSum, rightSum);
    }
    void pointUpdate(int node, int value)
    {
        pointUpdateUtil(0, 0, n - 1, node, value);
    }

    void pointUpdateUtil(int idx, int start, int end, int node, int value)
    {
        // O(Logn)
        if (start == end)
        {
            arr[node] = value;
            seg[idx] = value;
        }
        else
        {
            int mid = (start + end) / 2;
            if (node <= mid)
                pointUpdateUtil(2 * idx + 1, start, mid, node, value);
            else
                pointUpdateUtil(2 * idx + 2, mid + 1, end, node, value);
            seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
        }
    }
    void updateRange(int l, int r, int val)
    {
        updateRangeUtil(0, 0, n - 1, l, r, val);
    }

    void updateRangeUtil(int idx, int start, int end, int l, int r, int val)
    {
        if (lazy[idx] != 0)
        {
            seg[idx] = (end - start + 1) * lazy[idx];
            if (start != end)
            {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }

        if (r < start || end < l)
            return; // No overlap

        if (l <= start && end <= r)
        {
            seg[idx] = (end - start + 1) * val;
            if (start != end)
            {
                lazy[2 * idx + 1] += val;
                lazy[2 * idx + 2] += val;
            }
            return;
        }

        int mid = (start + end) / 2;
        updateRangeUtil(2 * idx + 1, start, mid, l, r, val);
        updateRangeUtil(2 * idx + 2, mid + 1, end, l, r, val);
        seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
    int queryRange(int l, int r)
    {
        return queryRangeUtil(0, 0, n - 1, l, r);
    }

    int queryRangeUtil(int idx, int start, int end, int l, int r)
    {
        if (lazy[idx] != 0)
        {
            seg[idx] = (end - start + 1) * lazy[idx];
            if (start != end)
            {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }

        if (r < start || end < l)
            return 0; // No overlap

        if (l <= start && end <= r)
            return seg[idx]; // Total overlap

        int mid = (start + end) / 2;
        int left = queryRangeUtil(2 * idx + 1, start, mid, l, r);
        int right = queryRangeUtil(2 * idx + 2, mid + 1, end, l, r);
        return merge(left, right);
    }
};