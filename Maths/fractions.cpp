//  when we want to deal with fractions in inverse i.e p/q= p*q^-1 (mod m)
// we just keep this x= p*q^-1 (mod m) and than to add to fractions f1 and f2
// we do f1+f2= (a/b)+(c/d)= a*b-1+b*d-1 (mod m) i.e we only need to keep the inverse value of fraction and not numerator and denominator

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