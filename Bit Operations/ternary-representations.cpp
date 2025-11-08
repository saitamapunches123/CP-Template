/*
In most cases we use binary(base 2) representation or decimal(base 10) representation.
But we can also use ternary(base 3) representation also.

For example:
15 in ternary = 120 =1*3^2+2*3^1+0*3^0


Why is ternart usefull?

as we increase the base the number of digits decreases required to represent a number.
to represent up to n we need logb(n)+1 digits in base b.

and the size of set we need to represent all values in 0ton = (logb(n)+1)*(b-1)  // max power*(b-1) 
as for each power we need 1*b^p , 2*b^p,3*b^p.... (b-1)*b^p

this size of set can be mimumum at 3 as for example here: 
https://www.codechef.com/problems/MAKEALL

*/
int digitsInBase(long long n, int base) {
    if (n == 0) return 1;
    return floor(log(n) / log(base)) + 1;
}


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


