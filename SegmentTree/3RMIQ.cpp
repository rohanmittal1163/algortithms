#include <bits/stdc++.h>
using namespace std;

class SegmentTreeMaxIndex
{
private:
    vector<int> tree; // stores index of max element
    vector<int> arr;
    int n;

public:
    SegmentTreeMaxIndex(const vector<int> &input)
    {
        arr = input;
        n = arr.size();
        tree.resize(4 * n);
        build(0, 0, n - 1);
    }

    void build(int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = start; // store index
        }
        else
        {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);

            int leftIndex = tree[2 * node + 1];
            int rightIndex = tree[2 * node + 2];
            tree[node] = (arr[leftIndex] >= arr[rightIndex]) ? leftIndex : rightIndex;
        }
    }

    int queryMaxIndex(int l, int r)
    {
        return queryUtil(0, 0, n - 1, l, r);
    }

    int queryUtil(int node, int start, int end, int l, int r)
    {
        if (r < start || end < l)
            return -1; // no overlap

        if (l <= start && end <= r)
            return tree[node]; // total overlap

        int mid = (start + end) / 2;
        int leftIndex = queryUtil(2 * node + 1, start, mid, l, r);
        int rightIndex = queryUtil(2 * node + 2, mid + 1, end, l, r);

        if (leftIndex == -1)
            return rightIndex;
        if (rightIndex == -1)
            return leftIndex;
        return (arr[leftIndex] >= arr[rightIndex]) ? leftIndex : rightIndex;
    }

    void update(int idx, int value)
    {
        arr[idx] = value;
        updateUtil(0, 0, n - 1, idx);
    }

    void updateUtil(int node, int start, int end, int idx)
    {
        if (start == end)
        {
            tree[node] = start;
        }
        else
        {
            int mid = (start + end) / 2;
            if (idx <= mid)
                updateUtil(2 * node + 1, start, mid, idx);
            else
                updateUtil(2 * node + 2, mid + 1, end, idx);

            int leftIndex = tree[2 * node + 1];
            int rightIndex = tree[2 * node + 2];
            tree[node] = (arr[leftIndex] >= arr[rightIndex]) ? leftIndex : rightIndex;
        }
    }
};
