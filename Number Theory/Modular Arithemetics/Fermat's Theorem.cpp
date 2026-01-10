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
/* 
USE ONLY IF MOD IS PRIME
a^−1 MOD=a^(MOD−2) MOD
*/
ll mod_inv_fermat(ll x, ll mod) {
    return mod_exp(x, mod - 2, mod); // Only works if mod is prime
}

/* GENERALIZATION: Fermat's Theorem
a^φ(m) ≡ 1 mod m  
for prime m , φ(m)=m-1
a^φ(m) = a^m-1=1 mod m
a^m-2=a^-1 mod m
so mod_inv(x,10)=x^(4-1)=x^(3)(mod 10)


Using Fermat's Theorem:

a^x mod m = a^(x mod φ(m)) mod m 
for prime m m=p
a^x mod p = a^(x mod p-1) mod p 

*/