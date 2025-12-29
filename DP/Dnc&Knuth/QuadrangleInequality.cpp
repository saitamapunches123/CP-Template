/*
Quadrangle Inequality is a property of cost functions. 
it says that for indices i ≤ j ≤ k ≤ l

cost(i,k) + cost(j,l) <= cost(i,l) + cost(j,k)
  (Overlapping Interval)  (Crossing Interval)
  
This is usefull for Dnc and Knuth optimization:
 as if cost function satisfies quadrangle inequality we can reduce Transition time using the result:

  opt(i)<=opt(i+1) // Monotonic Function

  opt(i)-> the optimal split index for i i.e the index for which dp[i] is minimum

*/