//  modinv(p*q) = mod inv((p*q% mod))

pair<ll,ll> add_fracts(pair<ll,ll> f1,pair<ll,ll> f2){
  auto [a,b]=f1;
  auto [c,d]=f2;
  ll den=(b*d)%mod;
  ll num=(a*d+b*c)%mod;
  return {num,den};
}
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
ll mod_inv(ll x, ll mod) {
    return mod_exp(x, mod - 2, mod); // Only works if mod is prime
}
// to represent p/q as p*mod_inv(q);
ll get_fract_inv(pair<ll,ll>& f){
  auto [a,b]=f;
  ll b_inv=mod_inv(b,mod);
  return (a*b_inv)%mod;
}