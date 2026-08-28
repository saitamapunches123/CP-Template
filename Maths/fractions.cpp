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
// to represent a/b as a*mod_inv(b);
ll get_fract_inv(ll a,ll b){
  ll b_inv=mod_inv(b,mod);
  return (a*b_inv)%mod;
}

// converts fraction to its minimal form
void reduce_fraction(pii &frac) {
    int &num = frac.first;
    int &den = frac.second;

    if (den == 0) return;          // undefined, leave as is
    if (num == 0) {
        den = 1;                  // canonical zero
        return;
    }

    int g = __gcd(abs(num), abs(den));
    num /= g;
    den /= g;

    if (den < 0) {                // keep denominator positive
        num = -num;
        den = -den;
    }
}
void display_fraction(pii &f){
    auto [p,q]=f;
    cout<<p<<" / "<<q<<endl;
}
bool is_greater(pii &a,pii &b){// return true if a>=b
    auto [p,q]=a;
    auto [r,s]=b;
    ll f1=(ll)p*s,f2=(ll)q*r;
    return f1>=f2;
    
}

pii mini(pii &a,pii &b){
    if(is_greater(a,b))
        return b;
    return a;
}

pii maxi(pii &a,pii &b){
    if(is_greater(a,b))
        return a;
    return b;
}