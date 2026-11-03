#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
// CLOSED HASHING (Open Addressing) - QUADRATIC PROBING
// On collision, jump in squares: (hash + i*i) % size
// Fixes PRIMARY clustering, but has SECONDARY clustering.
// Tip: keep load factor <= 0.5 and size prime so all slots are tried.
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
    vector<int> keys;
    vector<int> values;
    vector<SlotState> state;

    int hashFunction(int key)
    {
        return key % size;
    }

public:
    HashTable(int s)
    {
        size = s;
        keys.assign(size, -1);
        values.assign(size, -1);
        state.assign(size, EMPTY);
    }

    void insert(int key, int value)
    {
        int idx = hashFunction(key);

        for (int i = 0; i < size; i++)
        {
            int probe = (idx + i * i) % size; // quadratic step: +i^2

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
        cout << "Could not insert " << key << " (table too full)\n";
    }

    bool search(int key, int &value)
    {
        int idx = hashFunction(key);
        for (int i = 0; i < size; i++)
        {
            int probe = (idx + i * i) % size;

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
        int idx = hashFunction(key);
        for (int i = 0; i < size; i++)
        {
            int probe = (idx + i * i) % size;
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
    HashTable ht(7);

    ht.insert(10, 100); // 10 % 7 = 3
    ht.insert(17, 170); // 17 % 7 = 3 -> +1 -> 4
    ht.insert(24, 240); // 24 % 7 = 3 -> +1 busy -> +4 -> 0
    ht.insert(31, 310); // 31 % 7 = 3 -> +1,+4 busy -> +9 -> 5

    ht.display();

    int val;
    if (ht.search(31, val))
        cout << "\nFound 31 -> " << val << "\n";

    return 0;
}
