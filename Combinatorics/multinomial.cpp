/*
The multinomial coefficient gives the number of distinct arrangements of n items 
divided into r groups of sizes k1, k2, ..., kr such that:
    k1 + k2 + ... + kr = n where items of each group is identical
OR
    number of arrangements of the n items where each item belongs in a group i which has ki members
    and k1 + k2 + ... + kr = n

Multinomial(n; k1, k2, ..., kr) = n! / (k1! * k2! * ... * kr!)

*/


struct Combinatorics {
    vector<ll> facts, inv_facts;
    Combinatorics(int max_n) {
        facts.resize(max_n + 1);
        inv_facts.resize(max_n + 1);

        facts[0] = facts[1] = 1;
        for (ll i = 2; i <= max_n; i++) {
            facts[i] = (facts[i - 1] * i) % mod;
        }

        inv_facts[max_n] = mod_exp(facts[max_n], mod - 2, mod);
        for (ll i = max_n - 1; i >= 0; i--) {
            inv_facts[i] = (inv_facts[i + 1] * (i + 1)) % mod;
        }
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