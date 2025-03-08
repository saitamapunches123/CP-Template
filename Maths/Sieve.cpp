/*
TC: n log(logn) if we used harmonic series would have been nlogn.
Number of primes in n=n/log(n)
*/


void sieve(int n) {
    vector<bool> is_prime(n + 1, true);  
    is_prime[0] = is_prime[1] = false;   // 0 and 1 are not prime

    for (int p = 2; p * p <= n; p++) { //as prime facrots for n can be till root n only
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) { // Start from p^2
                is_prime[i] = false;
            }
        }
    }
    return is_prime;
}