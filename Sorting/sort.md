# Sorting Algorithms Summary

| Sort | Best | Average | Worst | Space | In-place | Stable | Adaptive |
|------|------|---------|-------|-------|----------|--------|----------|
| Bubble (`1bubble.cpp`) | O(n) | O(n²) | O(n²) | O(1) | Yes | Yes | Yes |
| Selection (`2selection.cpp`) | O(n²) | O(n²) | O(n²) | O(1) | Yes | No | No |
| Insertion (`3insertion.cpp`) | O(n) | O(n²) | O(n²) | O(1) | Yes | Yes | Yes |
| Merge (`4merge.cpp`) | O(n log n) | O(n log n) | O(n log n) | O(n) | No | Yes | No |
| Quick (`5quick.cpp`) | O(n log n) | O(n log n) | O(n²) | O(log n) | Yes | No | No |
| Heap (`6heap.cpp`) | O(n log n) | O(n log n) | O(n log n) | O(1) | Yes | No | No |
| Shell (`7shell.cpp`) | O(n log n) | ~O(n^1.5) | O(n²) | O(1) | Yes | No | Yes |
| Counting (`8counting.cpp`) | O(n + k) | O(n + k) | O(n + k) | O(n + k) | No | Yes | No |
| Radix (`9radix.cpp`) | O(d(n + b)) | O(d(n + b)) | O(d(n + b)) | O(n + b) | No | Yes | No |
| Bucket (`10bucket.cpp`) | O(n + k) | O(n + k) | O(n²) | O(n + k) | No | Yes | Partly |

## Terms
- **In-place**: uses O(1) (or at most O(log n) stack) extra memory beyond the input.
- **Stable**: equal elements keep their original relative order.
- **Adaptive**: runs faster when the input is already (nearly) sorted.
- **k**: range of values (counting) or number of buckets (bucket); **d**: digits; **b**: base.

## When to use what
- **Small or nearly sorted data**: Insertion (also Bubble with early exit).
- **Guaranteed O(n log n)**: Merge (stable, needs memory) or Heap (in-place, not stable).
- **Fastest general purpose in practice**: Quick (watch the worst case; use random or median-of-three pivots).
- **Few writes needed**: Selection (at most n-1 swaps).
- **Integers in a small range**: Counting. **Fixed-width integers or strings**: Radix.
- **Uniformly distributed floats**: Bucket.
- **Medium arrays, simple in-place code**: Shell.

## Notes
- Counting and Radix assume non-negative integers; Bucket assumes floats in [0, 1).
- Each file has a small `main()` so it can be compiled and run on its own, e.g. `g++ bubble.cpp -o bubble`.
