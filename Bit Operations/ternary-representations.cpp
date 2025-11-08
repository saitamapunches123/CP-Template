/*
In most cases we use binary(base 2) representation or decimal(base 10) representation.
But we can also use ternary(base 3) representation also.

For example:
15 in ternary = 120 =1*3^2+2*3^1+0*3^0


*/



// Function to convert an integer to its ternary representation (vector of ints)
vector<int> toTernary(int n) {
    if (n == 0) {
        return {0};
    }

    vector<int> ternary;
    while (n > 0) {
        ternary.push_back(n % 3);
        n /= 3;
    }

    reverse(ternary.begin(), ternary.end());
    return ternary;
}