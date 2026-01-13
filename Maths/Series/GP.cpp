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


ll nthtermMod(ll a,ll r,ll n){
  ll rn=mod_exp(r,n-1,mod);
  return (a*rn)%mod;
}

ll sumGPMod(ll a, ll r, ll n) {
    if (n == 0) return 0;

    a %= mod;
    r %= mod;

    if (r == 1)
        return (a * (n % mod)) % mod;

    ll rn = mod_exp(r, n, mod);
    ll num = (rn - 1 + mod) % mod;
    ll inv = mod_exp(r - 1, mod - 2, mod); // mod must be prime

    return a * num % mod * inv % mod;
}
//only works if r<1
ll sumInfiniteGP(ll a, ll r){
  return a/(1-r);  
}