#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
// CLOSED HASHING (Open Addressing) - DOUBLE HASHING
// Step size comes from a SECOND hash function:
//     index = (hash1(key) + i * hash2(key)) % size
//     hash2(key) = R - (key % R), with R a prime < size
// Best of the three: avoids primary AND secondary clustering.
// ------------------------------------------------------------

enum SlotState
{
    EMPTY,
    OCCUPIED,
    DELETED
};

class HashTable
{
    int size;
    int R; // prime smaller than size, used in hash2
    vector<int> keys;
    vector<int> values;
    vector<SlotState> state;

    int hash1(int key)
    {
        return key % size;
    }

    int hash2(int key)
    {
        // never returns 0, so step size is always valid
        return R - (key % R);
    }

public:
    HashTable(int s, int r)
    {
        size = s;
        R = r;
        keys.assign(size, -1);
        values.assign(size, -1);
        state.assign(size, EMPTY);
    }

    void insert(int key, int value)
    {
        int h1 = hash1(key);
        int h2 = hash2(key);

        for (int i = 0; i < size; i++)
        {
            int probe = (h1 + i * h2) % size;

            if (state[probe] != OCCUPIED)
            {
                keys[probe] = key;
                values[probe] = value;
                state[probe] = OCCUPIED;
                return;
            }
            if (state[probe] == OCCUPIED && keys[probe] == key)
            {
                values[probe] = value;
                return;
            }
        }
        cout << "Could not insert " << key << " (table full)\n";
    }

    bool search(int key, int &value)
    {
        int h1 = hash1(key);
        int h2 = hash2(key);

        for (int i = 0; i < size; i++)
        {
            int probe = (h1 + i * h2) % size;

            if (state[probe] == EMPTY)
                return false;

            if (state[probe] == OCCUPIED && keys[probe] == key)
            {
                value = values[probe];
                return true;
            }
        }
        return false;
    }

    void remove(int key)
    {
        int h1 = hash1(key);
        int h2 = hash2(key);
        for (int i = 0; i < size; i++)
        {
            int probe = (h1 + i * h2) % size;
            if (state[probe] == EMPTY)
                return;
            if (state[probe] == OCCUPIED && keys[probe] == key)
            {
                state[probe] = DELETED;
                return;
            }
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Slot " << i << ": ";
            if (state[i] == OCCUPIED)
                cout << "(" << keys[i] << ", " << values[i] << ")";
            else if (state[i] == DELETED)
                cout << "<deleted>";
            else
                cout << "<empty>";
            cout << "\n";
        }
    }
};

int main()
{
    // size = 7 (prime), R = 5 (prime < size)
    HashTable ht(7, 5);

    ht.insert(10, 100);
    ht.insert(17, 170);
    ht.insert(24, 240);
    ht.insert(31, 310);

    ht.display();

    int val;
    if (ht.search(24, val))
        cout << "\nFound 24 -> " << val << "\n";

    return 0;
}
