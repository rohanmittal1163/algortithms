#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
// REHASHING (Dynamic Resizing)
// When load factor (n/m) crosses a threshold (here 0.7),
// we grow the table and re-insert ALL keys with the new size.
// Uses linear probing for placement.
// Amortized cost per insert stays O(1).
// ------------------------------------------------------------

class HashTable
{
    int capacity;        // current table size (m)
    int count;           // number of items stored (n)
    vector<int> keys;
    vector<bool> occupied;
    const double LOAD_THRESHOLD = 0.7;

    int hashFunction(int key, int cap)
    {
        return key % cap;
    }

    // find next prime >= x (so table size stays prime)
    bool isPrime(int x)
    {
        if (x < 2)
            return false;
        for (int i = 2; (long long)i * i <= x; i++)
            if (x % i == 0)
                return false;
        return true;
    }
    int nextPrime(int x)
    {
        while (!isPrime(x))
            x++;
        return x;
    }

    // place a key using linear probing into given arrays
    void place(int key, vector<int> &k, vector<bool> &occ, int cap)
    {
        int idx = hashFunction(key, cap);
        for (int i = 0; i < cap; i++)
        {
            int probe = (idx + i) % cap;
            if (!occ[probe])
            {
                k[probe] = key;
                occ[probe] = true;
                return;
            }
        }
    }

    void rehash()
    {
        int newCap = nextPrime(capacity * 2);
        cout << "  [rehash] load factor exceeded -> growing "
             << capacity << " to " << newCap << "\n";

        vector<int> newKeys(newCap, -1);
        vector<bool> newOcc(newCap, false);

        // re-insert every existing key into the bigger table
        for (int i = 0; i < capacity; i++)
        {
            if (occupied[i])
                place(keys[i], newKeys, newOcc, newCap);
        }

        keys = newKeys;
        occupied = newOcc;
        capacity = newCap;
    }

public:
    HashTable(int cap = 5)
    {
        capacity = nextPrime(cap);
        count = 0;
        keys.assign(capacity, -1);
        occupied.assign(capacity, false);
    }

    void insert(int key)
    {
        // check load factor BEFORE inserting
        if ((double)(count + 1) / capacity > LOAD_THRESHOLD)
            rehash();

        place(key, keys, occupied, capacity);
        count++;
    }

    double loadFactor()
    {
        return (double)count / capacity;
    }

    void display()
    {
        cout << "Table (capacity " << capacity
             << ", items " << count
             << ", load " << fixed << setprecision(2) << loadFactor() << "):\n";
        for (int i = 0; i < capacity; i++)
        {
            cout << "  Slot " << i << ": ";
            cout << (occupied[i] ? to_string(keys[i]) : "<empty>") << "\n";
        }
    }
};

int main()
{
    HashTable ht(5);

    int data[] = {10, 17, 24, 31, 5, 12, 19};
    for (int x : data)
    {
        cout << "Inserting " << x << "\n";
        ht.insert(x);
    }

    cout << "\nFinal state:\n";
    ht.display();

    return 0;
}
