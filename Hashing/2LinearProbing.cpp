#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
// CLOSED HASHING (Open Addressing) - LINEAR PROBING
// On collision, check the next slot: (hash + i) % size
// Uses TOMBSTONES for safe deletion (DELETED != EMPTY).
// Load factor must stay <= 1.
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
            int probe = (idx + i) % size; // linear step: +1 each time

            // free slot (never used or deleted) -> place here
            if (state[probe] != OCCUPIED)
            {
                keys[probe] = key;
                values[probe] = value;
                state[probe] = OCCUPIED;
                return;
            }
            // key already present -> update
            if (state[probe] == OCCUPIED && keys[probe] == key)
            {
                values[probe] = value;
                return;
            }
        }
        cout << "Hash table is full! Cannot insert " << key << "\n";
    }

    bool search(int key, int &value)
    {
        int idx = hashFunction(key);
        for (int i = 0; i < size; i++)
        {
            int probe = (idx + i) % size;

            if (state[probe] == EMPTY)
                return false; // a never-used slot means key not here

            if (state[probe] == OCCUPIED && keys[probe] == key)
            {
                value = values[probe];
                return true;
            }
            // if DELETED, keep probing past the tombstone
        }
        return false;
    }

    void remove(int key)
    {
        int idx = hashFunction(key);
        for (int i = 0; i < size; i++)
        {
            int probe = (idx + i) % size;
            if (state[probe] == EMPTY)
                return;
            if (state[probe] == OCCUPIED && keys[probe] == key)
            {
                state[probe] = DELETED; // tombstone, not EMPTY
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
    ht.insert(17, 170); // 17 % 7 = 3 -> probes to 4
    ht.insert(24, 240); // 24 % 7 = 3 -> probes to 5
    ht.insert(4, 400);  // 4  % 7 = 4 -> probes to 6

    ht.display();

    int val;
    if (ht.search(24, val))
        cout << "\nFound 24 -> " << val << "\n";

    ht.remove(17);
    cout << "\nAfter removing 17 (tombstone left so 24 is still findable):\n";
    ht.display();

    if (ht.search(24, val))
        cout << "\n24 still found -> " << val << "\n";

    return 0;
}
