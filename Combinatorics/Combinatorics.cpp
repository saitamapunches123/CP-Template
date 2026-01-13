ll mod=1000000007;
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
struct Combinatorics {
    vector<ll> facts, inv_facts;
    Combinatorics(int max_n) {
        facts.resize(max_n + 1);
        inv_facts.resize(max_n + 1);

        facts[0] = facts[1] = 1; //assuming mod to be prime
        for (ll i = 2; i <= max_n; i++) {
            facts[i] = (facts[i - 1] * i) % mod;
        }

        inv_facts[max_n] = mod_exp(facts[max_n], mod - 2, mod);
        for (ll i = max_n - 1; i >= 0; i--) {
            inv_facts[i] = (inv_facts[i + 1] * (i + 1)) % mod;
        }
    }
    ll factorial(ll f){
      return facts[f];
    }
    ll nCr(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        ll num = facts[n];
        ll den = (inv_facts[r] * inv_facts[n - r]) % mod;
        return (num * den) % mod;
    }
    vector<ll> get_facts(){
      return facts;
    }
    ll nPr(ll n, ll r) {
        if (r < 0 || r > n) return 0;
        ll num = facts[n];
        ll den = inv_facts[n - r];
        return (num * den) % mod;
    }
    /*
    usefull to find the number of ways to distribute n identical items in k boxes
    OR
    number of solution to x1+x2+...xk=n for xi>=0
    ans=n+k-1 C n=n+k-1 C k-1
    */
    ll stars_and_bars(ll items,ll boxes){
      return nCr(items+boxes-1,items);
    }
    ll multinomial(ll n, vector<ll> ks) { //sum of ks should be n
        ll num = facts[n];
        ll den = 1;
        ll sum=0;
        for(auto k:ks)
        {den=(den*inv_facts[k])%mod;
        sum+=k;}
        if(sum!=n) return -1;
        return (num * den) % mod;
    }
};