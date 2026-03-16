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
// use this if mod is prime only
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



long long sumOfGP(long long r,long long n,long long m)
{
    // n = number of terms - 1
    // first term is assumed 1
    // multiply with first term if it is not a
    // r = common ratio
    if(n<0)
        return 0;
    if(n==0)
        return 1;
    if(n==1)
        return (1+r)%m;
    long long ans;
    if(n%2)
        ans=1ll*(1+r)*sumOfGP((1ll*r*r)%m,(n-1)/2,m);
    else
        ans=1+((1ll*r*(1+r))%m)*sumOfGP((1ll*r*r)%m,n/2-1,m);
    return ans%m;
}
// Use this for all gp mod may or may not be prime works in log n
ll sumOfGP(ll a,ll r,ll n,ll mod)
{
    ll ans=sumOfGP(r,n-1,mod);// return sum of 1+r+r*2+...r^n-1
    ans=(ans*a)%mod;
    return ans;
}