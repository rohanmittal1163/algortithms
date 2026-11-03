# Searching Algorithms Summary

## Comparison

| # | Algorithm | Best | Average | Worst | Space | Needs sorted? | Iterative / Recursive | Data assumption |
|---|-----------|------|---------|-------|-------|---------------|-----------------------|-----------------|
| 1 | Linear (`1linear.cpp`) | O(1) | O(n) | O(n) | O(1) iter / O(n) rec | No | Both | None |
| 2 | Binary (`2binary.cpp`) | O(1) | O(log n) | O(log n) | O(1) iter / O(log n) rec | Yes | Both | None (random access) |
| 3 | Jump (`3jump.cpp`) | O(1) | O(√n) | O(√n) | O(1) | Yes | Iterative | None |
| 4 | Interpolation (`4interpolation.cpp`) | O(1) | O(log log n) | O(n) | O(1) iter / recursive stack | Yes | Both | Uniformly distributed |
| 5 | Exponential (`5exponential.cpp`) | O(1) | O(log i) | O(log n) | O(1) | Yes | Iterative (+ binary search) | Unbounded / key near start |
| 6 | Ternary (`6ternary.cpp`) | O(1) | O(log₃ n) | O(log₃ n) | O(1) iter / O(log₃ n) rec | Yes (array) / unimodal fn | Both | Unimodal function for max/min |
| 7 | Fibonacci (`7fibonacci.cpp`) | O(1) | O(log n) | O(log n) | O(1) | Yes | Iterative | None |

`i` = index where the key is found, `n` = array size.

## Notes per algorithm
- **Linear**: the only option for unsorted or linked data; simple and fine for small inputs.
- **Binary**: the standard choice for sorted arrays. Use `lo + (hi - lo) / 2` to avoid overflow.
- **Jump**: jumps ahead in blocks of √n, then scans one block linearly. Only moves forward, which suits storage where going backward is expensive.
- **Interpolation**: guesses the position from the key's value, like looking up a name in a phone book. Very fast on uniform data, falls back to O(n) on skewed data (for example exponentially growing values).
- **Exponential**: doubles an index (1, 2, 4, 8, ...) until it passes the key, then binary searches that range. Works when the array size is unknown or infinite, and is quick when the key is near the front.
- **Ternary**: two midpoints split the range in three. For plain lookup it is slower than binary search (about 2 comparisons per step to shrink by 1/3, versus 1 per step to halve). Its real use is finding the maximum or minimum of a unimodal function; `6ternary.cpp` shows both.
- **Fibonacci**: splits the range by Fibonacci numbers instead of halves, using only addition and subtraction. Behaves like binary search with a different split.

## Quick choice guide
- Unsorted data: **Linear**.
- Sorted array, general case: **Binary**.
- Sorted, uniformly distributed numbers: **Interpolation**.
- Sorted, unknown size or key likely near the start: **Exponential**.
- Sorted, backward moves are costly: **Jump** (or Fibonacci).
- Peak of a function that rises then falls: **Ternary**.

## Running
Each file has a small `main()`, for example: `g++ binary.cpp -o binary`.
