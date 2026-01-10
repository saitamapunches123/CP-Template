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