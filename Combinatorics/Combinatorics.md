# Combinatorics Cheat Sheet

- All Combinatorics is recursion and all formulas can be broken down recursively
  - For Example: nCr=n-1Cr-1+n-1Cr
    - think of it as for any object x we can pick it (now from rest n-1 pick r-1) and NOT pick it (now from rest n-1 pick r)

| Pattern            | Use                                                                             | Formula                                                 |
| ------------------ | ------------------------------------------------------------------------------- | ------------------------------------------------------- |
| **nCr**            | Number of ways to choose r elements from n elements                             | `C(n, r) = n! / (r! (n-r)!)` |
| **nPr**            | Number of ways to choose and arrange r elements from n elements                            | `P(n, r) = n! / (n-r)!` |
| **Stars and Bars** | Number of ways to distribute n identical items into k distinct boxes                | `C(n+k-1, k-1)` for distributing n items into k boxes |
| **Multinomial**    | Number of ways to divide n elements into groups of sizes ( n_1, n_2, ..., n_k ) or Number of ways to arrange k identical objects of type n_1, n_2, ..., n_k ) | `n= n_1+n_2+ ...+n_k` `n! / (n1! n2! ... nk!)` ) |

- Stars and bars is basically Combination with repetetion i.e to pick n object from k distinct object S.T order doesnt matter (xi number of i th object picked)
- Stars = n bars=k-1 as xi = # of bars in the kth segement
- Stars and bars is identified when x1+x2+x3+...xk = n and xi>=0 (n+k-1)C(k-1) is the number of solutions of this
- Stars and bars deals with number of ways to pick/distribute identical items. multinomial deals with number of ways to arrange identical items
- [Question](https://www.geeksforgeeks.org/quizzes/gate-cs-2025-set-1/#:~:text=shop%20has%204%20distinct%20flavors%20of%20ice%2Dcream.%20One%20can%20purchase%20any%20number%20of%20scoops%20of%20any%20flavor.%20The%20order%20in%20which%20the%20scoops%20are%20purchased%20is%20inconsequential.%20If%20one%20wants%20to%20purchase)

## Number of ways to pick r object n times

  |                          | **Repetition Allowed**                          | **No Repetition**                              |
  |--------------------------|-----------------------------------------------|-----------------------------------------------|
  | **Order Matters (Permutation)** | r^n                                           | nPr = r! / (r-n)! |
  | **Order NOT Matters (Combination)** | n+r-1Cn=n+r-1Cr-1 | nCr            |

## nPr Properties
- nPr =n⋅n−1Pr−1

## Complement Law

- `n(A ∪ B) + n((A ∪ B)′) = n(U)` U -> universal set or Total`
- `n((A∪B)′) = n(A′∩B′)`
-  This is usefull as to calculate `n(A∩B) = n(U) - n(A′U B′)  valid+ invalid = Total` and n(A`U B`) can be calculate using `inclusion exclusion principle`



