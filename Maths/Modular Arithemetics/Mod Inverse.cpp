/*
To find inverse of x under mod must be 1 gcd(x,mod)==1 (if not then inverse DOESNT EXIST)

IF x and mod are co-primes then
1) USE FERMATS THEOREM if mod is prime
2) USE EXTENDED EUCLID ALGO if mod is not prime
both work in O(log(min(x,mod)))
*/