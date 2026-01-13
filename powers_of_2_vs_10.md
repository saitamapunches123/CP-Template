# Powers of 2 vs Powers of 10 — Cheat Sheet

Smallest power of 2 that is **strictly greater** than a given power of 10.

| Power of 10 | First power of 2 greater | Exact value |
|------------|--------------------------|-------------|
| 10¹ = 10 | 2⁴ | 16 |
| 10² = 100 | 2⁷ | 128 |
| 10³ = 1,000 | 2¹⁰ | 1,024 |
| 10⁴ = 10,000 | 2¹⁴ | 16,384 |
| 10⁵ = 100,000 | 2¹⁷ | 131,072 |
| 10⁶ = 10⁶ | 2²⁰ | 1,048,576 |
| 10⁷ | 2²⁴ | 16,777,216 |
| 10⁸ | 2²⁷ | 134,217,728 |
| 10⁹ | 2³⁰ | 1,073,741,824 |
| 10¹⁰ | 2³⁴ | ≈ 1.7 × 10¹⁰ |
| 10¹² | 2⁴⁰ | ≈ 1.1 × 10¹² |
| 10¹⁵ | 2⁵⁰ | ≈ 1.12 × 10¹⁵ |
| 10¹⁸ | 2⁶⁰ | ≈ 1.15 × 10¹⁸ |

---

## Quick CP Memory Rule

- Usefull in xor questions as xor of numbers from 1 to n will not have a more significant bit than n.
- https://codeforces.com/contest/862/problem/C

## TLE Constraints

- IF n is around 1e5 n*log^2(n) and n*sqrt(n) works
- but for n around 1e6 these Contranints may give TLE