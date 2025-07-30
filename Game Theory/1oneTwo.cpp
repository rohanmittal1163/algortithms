#include <iostream>
using namespace std;

string oneTwoGame(int n)
{
    return (n % 3 == 0) ? "Bob" : "Alice";
}

int main()
{
    int n;
    cin >> n;
    cout << oneTwoGame(n) << endl;
    return 0;
}
