# Mod Properties Cheat Sheet

## MOD TO LINEAR EQUATION:

`a*x ≡ k (mod n) ⇒ a*x = b * n + k ⇒ a*x - b * n = k`

## Bézout's Theorem:
- Bézout’s theorem states that for any given integers `x` and `n`, there exist integers `a` and `b` such that:
`a * x + b * n = gcd(x, n)   --{1}` (Proved in Extended Euclidian algo)

- This can be usd to solve linear congruences (modular equations) like:
`a * x ≡ k (mod n)`

- Converting into **linear Diophantine equation** as `a * x mod n = a * x - b * n`
`a * x ≡ k (mod n) ⇒ a * x - b * n = k`

- According to Bézout’s theorem, a * x - b * n = k has integer solutions `(a, b)` **if and only if** `gcd(x, n) divides k` (Multiplying equation 1 by k/gcd(x,n))
---
- Thus `a*x ≡ k (mod n)` has integer solutions **if and only if** `gcd(x, n) divides k`

## a*x mod n Series

- `a*x mod n ⇒ {0,x,2*x,3*x,4*x,....} mod n`
- From Above The series `only ocupies value which are divisible by gcd(a,n)`
- if `d=gcd(a,d), a*x mod n ⇒ {0,d,2*d,3*d,...(n/d-1)*d}` as n/d*d=n=0(mod n)
- Number of unique terms in series  = `n/d`.
- https://codeforces.com/contest/1091/problem/C

## Inverse:

### From Above:
`a*x ≡ k (mod m) ⇒ (a/d)*x ≡ (c/d) mod (m/d) , d = gcd(a, m)`   


| Case | Condition | Result / Notes |
|------|-----------|----------------|
| 1 | `d divides k` | gcd(a/d, m/d) = 1 → a/d and m/d are coprime → `Inverse Exists`. Use **Extended Euclidean Algorithm**(m/d not prime) or **Fermat's Theorem** (m/d is prime) to find inverse |
| 2 | `d does not divide k` | `Inverse Does Not Exist` |

### Fermat's Theorem