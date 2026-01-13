ll safe_multiply(ll a,ll b) { //return -1 if overflow
    if (a == 0 || b == 0) return 0;

    if (a > 0) {
        if (b > 0) {
            if (a > LLONG_MAX / b) return -1;
        } else { // b < 0
            if (b < LLONG_MIN / a) return -1;
        }
    } else { // a < 0
        if (b > 0) {
            if (a < LLONG_MIN / b) return -1;
        } else { // b < 0
            if (a < LLONG_MAX / b) return -1;
        }
    }
    return a * b;
}