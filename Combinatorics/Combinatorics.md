# Combinatorics Cheat Sheet

| Pattern            | Use                                                                             | Formula                                                 |
| ------------------ | ------------------------------------------------------------------------------- | ------------------------------------------------------- |
| **nCr**            | Number of ways to choose r elements from n elements                             | `C(n, r) = n! / (r! (n-r)!)` |
| **nPr**            | Number of ways to choose and arrange r elements from n elements                            | `P(n, r) = n! / (n-r)!` |
| **Stars and Bars** | Number of ways to distribute n identical items into k distinct boxes                | `C(n+k-1, k-1)` for distributing n items into k boxes |
| **Multinomial**    | Number of ways to divide n elements into groups of sizes ( n_1, n_2, ..., n_k ) or Number of ways to arrange k identical objects of type n_1, n_2, ..., n_k ) | `n= n_1+n_2+ ...+n_k` `n! / (n1! n2! ... nk!)` ) |


- Stars and bars is identified when x1+x2+x3+... = n and xi>=0
- Stars and bars deals with number of ways to pick/distribute identical items. multinomial deals with number of ways to arrange identical items

## Complement Law

- `n(A ∪ B) + n((A ∪ B)′) = n(U)` U -> universal set or Total`
- `n((A∪B)′) = n(A′∩B′)`
-  This is usefull as to calculate `n(A∩B) = n(U) - n(A′U B′)  valid+ invalid = Total` and n(A`U B`) can be calculate using `inclusion exclusion principle`


