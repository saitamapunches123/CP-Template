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
};