#include <bits/stdc++.h>
using namespace std;
void build(int idx, int low, int high, string arr, vector<vector<int>> &seg)
{
    if (low == high)
    {
        seg[idx][0] = arr[low] == '(';
        seg[idx][1] = arr[low] == ')';
        seg[idx][2] = 0;
        return;
    }
    int mid = (low + high) >> 1;
    build(2 * idx + 1, low, mid, arr, seg);
    build(2 * idx + 2, mid + 1, high, arr, seg);
    seg[idx][0] = seg[2 * idx + 1][0] + seg[2 * idx + 2][0] - min(seg[2 * idx + 1][0], seg[2 * idx + 2][1]);
    seg[idx][1] = seg[2 * idx + 1][1] + seg[2 * idx + 2][1] - min(seg[2 * idx + 1][0], seg[2 * idx + 2][1]);
    seg[idx][2] = seg[2 * idx + 1][2] + seg[2 * idx + 2][2] + min(seg[2 * idx + 1][0], seg[2 * idx + 2][1]);
}
vector<int> query(int idx, int l, int r, int low, int high, vector<vector<int>> &seg)
{
    if (r < low || high < l)
    {
        return vector<int>(3, 0);
    }
    if (l <= low && high <= r)
    {
        return seg[idx];
    }
    int mid = (low + high) >> 1;
    vector<int> left = query(2 * idx + 1, l, r, low, mid, seg);
    vector<int> right = query(2 * idx + 2, l, r, mid + 1, high, seg);
    return {left[0] + right[0] - min(left[0], right[1]), left[1] + right[1] - min(left[0], right[1]),
            left[2] + right[2] + min(left[0], right[1])};
}
int main()
{
    string s;
    cin >> s;
    int m, l, r;

    cin >> m;
    int n = s.length();
    vector<int> ans(m, 0);
    vector<vector<int>> seg(4 * n, vector<int>(3, 0));
    build(0, 0, n - 1, s, seg);

    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        ans[i] = query(0, l - 1, r - 1, 0, n - 1, seg)[2];
    }
    for (auto i : ans)
    {
        cout << i * 2 << endl;
    }

    return 0;
}