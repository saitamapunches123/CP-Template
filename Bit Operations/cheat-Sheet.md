# Bit Operations Cheat Sheet

## Maximization Trick (MSB Dominance)

- Always reason using the **Most Significant Bit (MSB)**.
- For any `k ≥ 1`:
  
  \[
  2^k > \sum_{i=0}^{k-1} 2^i
  \]

- Hence, **having a higher MSB always guarantees a larger value**, regardless of lower bits.
- Very useful in greedy and XOR / bitmask problems.
-  https://codeforces.com/contest/1383/problem/B
