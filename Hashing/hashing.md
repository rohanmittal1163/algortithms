# 🔑 Hashing — Data Structure Notes

## Overview

- **Hashing** is a technique to store and find data in **O(1) average time**.
- Instead of searching one by one, we use a **formula** to jump straight to where the data lives.
- The formula is called a **hash function**, and the storage is called a **hash table**.

> Think of a library: instead of checking every book, a catalog number tells you the exact shelf.

---

## Why Hashing?

| Operation | Array (unsorted) | Sorted Array | BST (balanced) | **Hash Table** |
|---|---|---|---|---|
| Search | O(n) | O(log n) | O(log n) | **O(1) avg** |
| Insert | O(1) | O(n) | O(log n) | **O(1) avg** |
| Delete | O(n) | O(n) | O(log n) | **O(1) avg** |

> Worst case for hashing is O(n) (when everything collides), but on average it is O(1).

---

## Key Terminology

| Term | Simple Meaning |
|---|---|
| **Key** | The thing you want to store/search (e.g., a roll number) |
| **Value** | The data attached to the key (e.g., student details) |
| **Hash Function** | Formula that turns a key into a number |
| **Hash Code** | The raw number the hash function produces |
| **Index / Slot / Bucket** | The actual position in the table (`hashCode % tableSize`) |
| **Hash Table** | The array where data is stored |
| **Collision** | Two keys landing on the same index |
| **Load Factor (α)** | How full the table is → `α = n / m` |

Here `n` = number of items stored, `m` = size of the table.

---

## 1. Hash Function

A **hash function** takes a key and returns an index.

```
index = hashFunction(key) % tableSize
```

### Properties of a GOOD hash function
1. **Deterministic** — same key always gives the same index.
2. **Uniform distribution** — spreads keys evenly, fewer collisions.
3. **Fast to compute** — should be cheap (O(1)).
4. **Uses the whole key** — every part of the key affects the result.
5. **Avalanche effect** — a tiny change in key changes the index a lot.

### Common techniques

| Method | Formula / Idea |
|---|---|
| **Division** | `key % m` (pick `m` as a prime number) |
| **Multiplication** | `floor(m * (key * A mod 1))`, `A ≈ 0.618` |
| **Mid-Square** | square the key, take middle digits |
| **Folding** | break key into parts, add them up |
| **String Hash (rolling)** | `hash = hash * p + char`, with prime `p` |

---

## 2. Collisions

A **collision** happens when two different keys map to the **same index**.

> Collisions are **unavoidable** — by the **Pigeonhole Principle**, if you have more keys than slots, at least two must share a slot.

There are **two main families** of solutions:

```
Collision Handling
├── Open Hashing   (Separate Chaining)  → store OUTSIDE the table
└── Closed Hashing (Open Addressing)    → store INSIDE the table
        ├── Linear Probing
        ├── Quadratic Probing
        └── Double Hashing
```

> ⚠️ Naming is confusing:
> - **Open Hashing = Separate Chaining = Closed Addressing**
> - **Closed Hashing = Open Addressing**

---

## 3. Open Hashing (Separate Chaining)

Each slot holds a **linked list** (or vector) of all keys that hash there.

```
index 0 → [ ]
index 1 → [ 21 ] → [ 31 ] → [ 41 ]
index 2 → [ 12 ]
```

| Point | Detail |
|---|---|
| **Insert** | Add to the list at that index — O(1) |
| **Search** | Go to index, walk the list — O(1 + α) |
| **Delete** | Remove node from list |
| **Load factor** | Can be **> 1** (lists can grow) |

**Advantages**
- Simple to implement.
- Table never "fills up".
- Deletion is easy.
- Works well even with high load factor.

**Disadvantages**
- Extra memory for pointers.
- Poor cache performance (linked lists scattered in memory).
- If one list gets long, search degrades to O(n).

---

## 4. Closed Hashing (Open Addressing)

All data is stored **inside the table itself**. On collision, we **probe** (look for the next free slot).

Load factor **must be ≤ 1** (can't store more items than slots).

### a) Linear Probing

Check the next slot, one at a time.

```
index = (hash(key) + i) % m      where i = 0, 1, 2, 3...
```

- **Problem: Primary Clustering** — long runs of filled slots form and grow, slowing things down.

### b) Quadratic Probing

Jump in increasing squares.

```
index = (hash(key) + i²) % m      where i = 0, 1, 2, 3...
```

- **Fixes** primary clustering.
- **Problem: Secondary Clustering** — keys with the same start follow the same jump pattern.

### c) Double Hashing

Use a **second hash function** to decide the step size.

```
index = (hash1(key) + i * hash2(key)) % m
hash2(key) = R - (key % R)        where R is a prime < m
```

- **Best** of the three — avoids both primary and secondary clustering.
- Slightly more computation (two hash functions).

### Deletion problem (important!)
In open addressing, you **cannot just empty a slot** on delete — it would break the probe chain for other keys.
- **Fix: Tombstones (lazy deletion)** — mark the slot as `DELETED` instead of `EMPTY`. Searches skip over it; inserts can reuse it.

---

## 5. Performance — Formulas

Let **α = n / m** (load factor).

### Separate Chaining
| Search type | Avg comparisons |
|---|---|
| **Unsuccessful** | `α` |
| **Successful** | `1 + α/2` |

### Open Addressing — Linear Probing
| Search type | Avg probes |
|---|---|
| **Successful** | `½ (1 + 1/(1−α))` |
| **Unsuccessful** | `½ (1 + 1/(1−α)²)` |

### Open Addressing — Double Hashing (random probing)
| Search type | Avg probes |
|---|---|
| **Successful** | `(1/α) · ln(1/(1−α))` |
| **Unsuccessful** | `1/(1−α)` |

> 🔑 Takeaway: as **α → 1**, open addressing gets very slow. Keep α below ~0.7.

---

## 6. Rehashing (Resizing)

When the table gets too full (e.g., **α > 0.7**), performance drops.

**Rehashing steps:**
1. Create a **new, bigger table** (usually **double** the size, often next prime).
2. Re-run the hash function on **every existing key** (indices change because `m` changed).
3. Insert all old keys into the new table.

- Cost of one rehash: **O(n)**.
- But it happens rarely, so **amortized cost stays O(1)** per insert.

---

## 7. Chaining vs Open Addressing (Summary)

| Feature | Separate Chaining | Open Addressing |
|---|---|---|
| Where data lives | Outside (linked lists) | Inside the table |
| Load factor | Can be > 1 | Must be ≤ 1 |
| Extra memory | Yes (pointers) | No |
| Cache friendly | ❌ No | ✅ Yes |
| Deletion | Easy | Needs tombstones |
| Clustering | None | Yes (primary/secondary) |

---

## 8. Cryptographic vs Non-Cryptographic Hashing

| | Non-Cryptographic | Cryptographic |
|---|---|---|
| **Goal** | Speed, even distribution | Security |
| **Examples** | Division, Multiplication, MurmurHash | MD5, SHA-1, SHA-256 |
| **Reversible?** | Doesn't matter | Must be practically **impossible** to reverse |
| **Used in** | Hash tables | Passwords, signatures, integrity checks |

**Cryptographic hash properties:**
- **One-way** (can't get key back from hash).
- **Collision-resistant** (hard to find two inputs with same hash).
- **Avalanche effect** (tiny input change → totally different hash).

> For passwords, always add a **salt** (random value) before hashing, and use slow hashes like **bcrypt / scrypt / Argon2**.

---

## 9. Advantages & Disadvantages of Hashing

**Advantages**
- O(1) average search, insert, delete.
- Simple and intuitive.
- Great for lookups, caching, dedup.

**Disadvantages**
- Worst case O(n) (bad hash / too many collisions).
- No ordering — can't do range queries or "next smallest" easily (use a tree for that).
- Needs a good hash function.
- Resizing is costly (though amortized O(1)).

---

## 10. Algorithms / Problems that USE Hashing

| Problem | How hashing helps |
|---|---|
| **Two Sum** | Store seen numbers in a map, check for complement |
| **Group Anagrams** | Sorted string as key |
| **Subarray Sum = K** | Prefix sum stored in map |
| **Longest Consecutive Sequence** | Set for O(1) neighbor lookup |
| **First Non-Repeating Char** | Frequency map |
| **Find Duplicates** | Set membership check |
| **LRU Cache** | HashMap + Doubly Linked List |
| **Consistent Hashing** | Hash ring for distributed load balancing |
| **Bloom Filter** | Bit array + multiple hashes (probabilistic membership) |

---

## 11. Real-Life / Production Uses

- **Databases** — hash indexes for fast key lookups.
- **Caches** — Redis, Memcached, CDN caches, browser caches.
- **Distributed systems** — **Consistent hashing** for sharding & load balancing (Cassandra, DynamoDB).
- **Passwords** — bcrypt / scrypt / Argon2 with salt.
- **Data integrity** — file checksums, **Git commit IDs (SHA-1)**, blockchain.
- **Deduplication** — detect duplicate files/blocks by hash.
- **Compilers** — symbol tables for variable/function lookup.
- **Bloom filters** — Cassandra, Chrome's malicious-URL check, spell checkers.
- **Security** — digital signatures, SSL/TLS certificates.
- **Language built-ins** — C++ `unordered_map`/`unordered_set`, Java `HashMap`, Python `dict`.

---

## Files in this folder

| File | Topic |
|---|---|
| `1SeparateChaining.cpp` | Open hashing with linked lists |
| `2LinearProbing.cpp` | Open addressing, step +1 |
| `3QuadraticProbing.cpp` | Open addressing, step +i² |
| `4DoubleHashing.cpp` | Two hash functions |
| `5Rehashing.cpp` | Dynamic resize when load factor high |
| `6HashFunctions.cpp` | Division, mid-square, folding, string hash |
