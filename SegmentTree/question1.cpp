#include <bits/stdc++.h>
using namespace std;
class SGTree
{
private:
    vector<int> seg;

public:
    SGTree(int n)
    {
        seg.resize(4 * n);
    }

    void build(bool isOr, int idx, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(!isOr, 2 * idx + 1, low, mid, arr);
        build(!isOr, 2 * idx + 2, mid + 1, high, arr);
        if (isOr)
        {
            seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
        }
        else
        {
            seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
        }
    }

    void update(bool isOr, int idx, int low, int high, vector<int> &arr, int i, int val)
    {
        if (low == high)
        {
            seg[idx] = val;
            return;
        }
        int mid = (low + high) >> 1;
        if (i <= mid)
        {
            update(!isOr, 2 * idx + 1, low, mid, arr, i, val);
        }
        else
        {
            update(!isOr, 2 * idx + 2, mid + 1, high, arr, i, val);
        }
        if (isOr)
        {
            seg[idx] = seg[2 * idx + 1] | seg[2 * idx + 2];
        }
        else
        {
            seg[idx] = seg[2 * idx + 1] ^ seg[2 * idx + 2];
        }
    }
    int getRootVal()
    {
        return seg[0];
    }
};

int main()
{
    int n, m, temp, pos, val, j = 0;
    cin >> n >> m;
    int totEle = 1 << n;
    vector<int> arr(totEle, 0), ans(m, 0);
    for (int i = 0; i < totEle; i++)
    {
        cin >> temp;
        arr[i] = temp;
    }
    SGTree s(totEle);
    s.build(n % 2, 0, 0, totEle - 1, arr);

    while (j != m)
    {
        cin >> pos >> val;
        s.update(n % 2, 0, 0, totEle - 1, arr, pos - 1, val);
        ans[j++] = s.getRootVal();
    }
    for (auto i : ans)
    {
        cout << i << endl;
    }

    return 0;
}