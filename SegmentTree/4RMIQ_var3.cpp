#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> seg, heights;
    int n;

public:
    Solution()
    {
        seg.clear();
        heights.clear();
        n = 0;
    }
    void buildTree(int idx, int start, int end)
    {
        if (start == end)
            seg[idx] = start;
        else
        {
            int mid = (start + end) >> 1;
            buildTree(2 * idx + 1, start, mid);
            buildTree(2 * idx + 2, mid + 1, end);
            seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
        }
    }
    int merge(int l, int r)
    {
        return heights[l] >= heights[r] ? l : r;
    }
    bool isValid(int idx, int l, int r)
    {
        return (heights[idx] > heights[l] && heights[idx] > heights[r]);
    }
    int query(int l, int r)
    {
        return queryUtil(0, 0, n - 1, l, r);
    }
    int queryUtil(int idx, int start, int end, int l, int r)
    {
        if (r < start || end < l)
            return -1;

        if (l <= start && end <= r)
            return seg[idx];

        int mid = (start + end) >> 1,
            leftIdx = queryUtil(2 * idx + 1, start, mid, l, r),
            rightIdx = queryUtil(2 * idx + 2, mid + 1, end, l, r);

        if (leftIdx == -1)
            return rightIdx;

        if (rightIdx == -1)
            return leftIdx;

        return merge(leftIdx, rightIdx);
    }
    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
    {
        int n = heights.size(),
            q = queries.size();

        this->n = n;
        this->heights = heights;

        seg.assign(4 * n, 0);
        buildTree(0, 0, n - 1);

        vector<int> ans(q, -1);
        for (int i = 0; i < q; i++)
        {
            int l = min(queries[i][0], queries[i][1]),
                r = max(queries[i][0], queries[i][1]);

            if (l == r)
            {
                ans[i] = l;
                continue;
            }

            if (heights[r] > heights[l])
            {
                ans[i] = r;
                continue;
            }

            int start = r + 1,
                end = n - 1,
                mid;
            while (start <= end)
            {
                mid = start + (end - start) / 2;
                int idx = query(start, mid);
                if (isValid(idx, l, r))
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            if (start == n)
                ans[i] = -1;
            else
                ans[i] = start;
        }
        return ans;
    }
};