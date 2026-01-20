# Time & Space Complexity Cheat Sheet (CP)

## Rule of thumb
> ~2×10^8 simple operations ≈ 1 second (depends on judge & constants)

## Time Complexity Based on `n`

### ⚠️ **ALL THESE VALUES ARE APRROX**
- A badly written n^2 solution might TLE but a better simpler might pass
- If `n ≤ 500` n³ might fail for 1s but pass for 3 s

| n (approx) | Acceptable Time Complexity |
|-----------|----------------------------|
| n ≤ 10 | O(n!), O(2^n) |
| n ≤ 12 | O(n!), O(2^n) |
| n ≤ 20 | O(2^n · n) |
| n ≤ 25 | O(2^n) |
| n ≤ 100 | O(n⁴) |
| n ≤ 500 | O(n³) (only optimized C++) |
| n ≤ 10⁴ | O(n²) (tight) |
| n ≤ 10⁵ | O(n√n), O(n log n),O(n log² n) |
| n ≤ 10⁶ | O(n log n) |
| n ≤ 10⁷ | O(n) |
| n ≥ 10⁸ | O(log n), O(1) |

---

## 💾 Memory Constraints
### ⚠️ **MLE usually happens before TLE** Thus it may be n^3 Time is fine But n^3 space is the issue

### How to estimate memory

- `Size in MB ≈ size of array* size of type of array(in bytes)/1e6`
- For ex: `int arr[1e7]` ≈ 1e7*4/1e6 ≈ 40 MB


### References
- https://codeforces.com/blog/entry/98210
- https://codeforces.com/blog/entry/21344