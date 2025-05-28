#include <bits/stdc++.h>
using namespace std;
// count inversion
int merge(int low, int mid, int high, vector<int> &arr)
{
    int i = low;
    int j = mid + 1;
    vector<int> v;
    int ans = 0;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            v.push_back(arr[i]);
            i++;
        }
        else
        {
            v.push_back(arr[j]);
            ans += mid - i + 1;
            j++;
        }
    }
    while (i <= mid)
    {
        v.push_back(arr[i]);
        i++;
    }
    while (j <= high)
    {
        v.push_back(arr[j]);
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = v[i - low];
    }
    return ans;
}
int mergeSort(int low, int high, vector<int> &arr)
{
    if (low >= high)
    {
        return 0;
    }
    int mid = (low + high) >> 1;
    return mergeSort(low, mid, arr) +
           mergeSort(mid + 1, high, arr) +
           merge(low, mid, high, arr);
}
int main()
{
    vector<int> arr = {1, 20, 6, 4, 5};
    int n = arr.size();
    cout << mergeSort(0, n - 1, arr);
    // for (auto i : arr)
    // {
    //     cout << i << " ";
    // }
    return 0;
}
