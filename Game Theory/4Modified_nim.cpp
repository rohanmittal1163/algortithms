// In a modified version of the Game of Nim, two players—Alice and Bob—are playing with an array of integers.
// Alice can remove any number from the array that is a multiple of 3, while Bob can remove any number that is a
// multiple of 5. If a number is divisible by both 3 and 5(i.e., divisible by 15), it can be removed by either player,
// but they take turns starting with Alice.The game continues until no valid moves remain, and the player unable to make
// a move loses.Both players play optimally, and Alice always starts first.The goal is to determine who will win the game.
#include <iostream>
#include <vector>
using namespace std;

string getWinner(const vector<int> &arr, int n)
{
    int count3 = 0, count5 = 0, commonCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 3 == 0 && arr[i] % 5 == 0)
        {
            commonCount++;
        }
        else if (arr[i] % 3 == 0)
        {
            count3++;
        }
        else if (arr[i] % 5 == 0)
        {
            count5++;
        }
    }

    if (commonCount % 2 == 0)
    {
        return (count3 > count5) ? "ALICE" : "BOB";
    }
    else
    {
        return (count3 >= count5) ? "ALICE" : "BOB";
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << getWinner(arr, n) << endl;

    return 0;
}
