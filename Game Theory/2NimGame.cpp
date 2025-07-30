#include <iostream>
using namespace std;

string nimGame(int piles[], int n)
{
    int xorSum = 0;
    for (int i = 0; i < n; ++i)
        xorSum ^= piles[i];

    return (xorSum == 0) ? "Bob" : "Alice";
}

int main()
{
    int n;
    cin >> n;
    int piles[n];
    for (int i = 0; i < n; ++i)
        cin >> piles[i];

    cout << nimGame(piles, n) << endl;
    return 0;
}
