#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
// COMMON HASH FUNCTIONS (demo)
// Shows the classic ways to turn a key into an index.
// ------------------------------------------------------------

// 1) DIVISION METHOD: key % m  (pick m prime)
int divisionHash(int key, int m)
{
    return key % m;
}

// 2) MULTIPLICATION METHOD: floor(m * (key*A mod 1)), A ~ 0.618
int multiplicationHash(int key, int m)
{
    double A = 0.6180339887; // (sqrt(5)-1)/2, Knuth's suggestion
    double frac = key * A;
    frac = frac - floor(frac); // fractional part only
    return (int)(m * frac);
}

// 3) MID-SQUARE METHOD: square the key, take middle digits
int midSquareHash(int key, int m)
{
    long long sq = (long long)key * key;
    string s = to_string(sq);

    // take 2 middle digits (or fewer if small)
    int len = s.size();
    int mid = len / 2;
    int start = max(0, mid - 1);
    string midDigits = s.substr(start, 2);

    return stoi(midDigits) % m;
}

// 4) FOLDING METHOD: split digits into chunks of 2 and add
int foldingHash(int key, int m)
{
    int sum = 0;
    while (key > 0)
    {
        sum += key % 100; // take last 2 digits
        key /= 100;
    }
    return sum % m;
}

// 5) STRING HASH (polynomial rolling hash)
int stringHash(const string &str, int m)
{
    const int p = 31; // small prime, good for lowercase letters
    long long hash = 0;
    long long pow = 1;
    for (char c : str)
    {
        hash = (hash + (c - 'a' + 1) * pow) % m;
        pow = (pow * p) % m;
    }
    return (int)hash;
}

int main()
{
    int m = 10; // table size
    int key = 12345;

    cout << "Key = " << key << ", table size = " << m << "\n\n";
    cout << "Division method      : " << divisionHash(key, m) << "\n";
    cout << "Multiplication method: " << multiplicationHash(key, m) << "\n";
    cout << "Mid-square method    : " << midSquareHash(key, m) << "\n";
    cout << "Folding method       : " << foldingHash(key, m) << "\n";

    cout << "\nString hashing:\n";
    cout << "  \"apple\"  -> " << stringHash("apple", 1000) << "\n";
    cout << "  \"banana\" -> " << stringHash("banana", 1000) << "\n";

    return 0;
}
