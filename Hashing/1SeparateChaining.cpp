#include <bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------
// OPEN HASHING (Separate Chaining)
// Each bucket is a linked list. On collision, we just append.
// Load factor can be > 1 (lists grow as needed).
// ------------------------------------------------------------

class HashTable
{
    int size;                    // number of buckets
    vector<list<pair<int, int>>> table; // each bucket: list of (key, value)

    int hashFunction(int key)
    {
        return key % size;       // division method
    }

public:
    HashTable(int s)
    {
        size = s;
        table.resize(size);
    }

    // Insert or update a key
    void insert(int key, int value)
    {
        int idx = hashFunction(key);

        // if key already exists, update it
        for (auto &p : table[idx])
        {
            if (p.first == key)
            {
                p.second = value;
                return;
            }
        }
        // else add new node to the chain
        table[idx].push_back({key, value});
    }

    // Search returns true and sets value if found
    bool search(int key, int &value)
    {
        int idx = hashFunction(key);
        for (auto &p : table[idx])
        {
            if (p.first == key)
            {
                value = p.second;
                return true;
            }
        }
        return false;
    }

    // Delete a key from its chain
    void remove(int key)
    {
        int idx = hashFunction(key);
        auto &chain = table[idx];
        for (auto it = chain.begin(); it != chain.end(); ++it)
        {
            if (it->first == key)
            {
                chain.erase(it);
                return;
            }
        }
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Bucket " << i << ":";
            for (auto &p : table[i])
            {
                cout << " -> (" << p.first << ", " << p.second << ")";
            }
            cout << "\n";
        }
    }
};

int main()
{
    HashTable ht(7);

    ht.insert(10, 100);
    ht.insert(17, 170); // 17 % 7 == 3
    ht.insert(3, 300);  // 3  % 7 == 3  -> collision with 17
    ht.insert(24, 240); // 24 % 7 == 3  -> another collision

    ht.display();

    int val;
    if (ht.search(3, val))
        cout << "\nFound key 3 with value " << val << "\n";

    ht.remove(17);
    cout << "\nAfter removing 17:\n";
    ht.display();

    return 0;
}
