#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> seg;

public:
    Solution()
    {
        seg.clear();
    }

    long long query(int idx, int start, int end, int l, int r)
    {
        if (r < start || end < l)
            return 0;

        if (l <= start && end <= r)
            return seg[idx];

        int mid = start + (end - start) / 2;
        return query(2 * idx + 1, start, mid, l, r) + query(2 * idx + 2, mid + 1, end, l, r);
    }

    void update(int idx, int start, int end, int i)
    {
        if (start == end)
        {
            seg[idx] = 1;
            return;
        }
        int mid = start + (end - start) / 2;
        if (i <= mid)
            update(2 * idx + 1, start, mid, i);
        else
            update(2 * idx + 2, mid + 1, end, i);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }
    long long goodTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        long long n = nums1.size(), ans = 0;
        seg.assign(4 * n, 0);

        vector<long long> idx(n, -1);

        for (int i = 0; i < n; i++)
        {
            idx[nums2[i]] = i;
        }

        update(0, 0, n - 1, idx[nums1[0]]);
        for (int i = 1; i < n; i++)
        {
            long long j = idx[nums1[i]],
                      leftCommonCount = query(0, 0, n - 1, 0, j - 1),
                      leftUncommonCount = i - leftCommonCount,
                      rightCommonCount = n - 1 - j - leftUncommonCount;
            ans += leftCommonCount * rightCommonCount * 1LL;
            update(0, 0, n - 1, j);
        }
        return ans;
    }
};