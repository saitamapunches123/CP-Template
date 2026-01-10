ll sum_n(ll n) {
    return n * (n + 1) / 2;
}

ll sum_n_sq(ll n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}

ll sum_n_cube(ll n) {
    ll s = n * (n + 1) / 2;
    return s * s;
}

ll sumLR(ll l,ll r){ // sum of l,l+1,....r
    ll sz=(r-l+1),sum=(l+r);
    return (sz*sum)/2;
}


int inv2 = mod_inv_fermat(2,mod);
ll sumLRMod(ll l,ll r){ // sum of l,l+1,....r under mod m 
    ll sz=(r-l+1)%mod;
    int sum=(l+r)%mod;
    int ans=(sz*sum)%mod;
    return (ans*inv2)%mod;
}