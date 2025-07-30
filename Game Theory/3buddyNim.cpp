#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void buddyNim(vector<int> &arr1, vector<int> &arr2)
{
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int i = 0, j = 0;

    // Skip leading zeros
    while (i < arr1.size() && arr1[i] == 0)
        i++;
    while (j < arr2.size() && arr2[j] == 0)
        j++;

    // Compare remaining elements
    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] != arr2[j])
        {
            cout << "ALICE" << endl;
            return;
        }
        i++;
        j++;
    }

    // If both arrays have same size and elements
    if (i == arr1.size() && j == arr2.size())
        cout << "BOB" << endl;
    else
        cout << "ALICE" << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr1(n), arr2(n);

    for (int i = 0; i < n; ++i)
        cin >> arr1[i];
    for (int i = 0; i < n; ++i)
        cin >> arr2[i];

    buddyNim(arr1, arr2);
    return 0;
}
