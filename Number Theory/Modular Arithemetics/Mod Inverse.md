### To find inverse of x under mod must be 1 gcd(x,mod)==1 (if not then inverse DOESNT EXIST)

| Case | Condition | Method to Use | Notes | Time Complexity |
|-----:|-----------|---------------|-------|-----------------|
| 1 | `gcd(x, mod) = 1` **and** `mod` is prime | **Fermat’s Little Theorem** | Compute `x^(mod−2) mod mod` | `O(log mod)` |
| 2 | `gcd(x, mod) = 1` **and** `mod` is not prime | **Extended Euclidean Algorithm** | Find `a, b` such that `ax + b·mod = 1` → `a` is inverse | `O(log(min(x, mod)))` |
| 3 | `gcd(x, mod) ≠ 1` | ❌ **Inverse does not exist** | No solution | — |
