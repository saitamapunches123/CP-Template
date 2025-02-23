//Binary exponeantation
ll mod_exp(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}
/* If x,mod are NOT co-primes no mod inverse use something else
for ex: mod=5,x=10 can't use mod_inv
IF mod is prime
a^−1 MOD=a^(MOD−2) MOD
*/
ll mod_inv(ll x, ll mod) {
    return mod_exp(x, mod - 2, mod); // Only works if mod is prime
}

/* GENERALIZATION: Fermat's Theorem

mod_inv(a,m)=a^(phi(m))-1 (mod m)
phi(p)=p-1 if p is prime
phi(p^k)=p^k-p^(k-1)
phi(a.b)=phi(a).phi(b)
so phi(10)=phi(2)*phi(5)=1*4=4
so mod_inv(x,10)=x^(4-1)=x^(3)(mod 10)

*/

