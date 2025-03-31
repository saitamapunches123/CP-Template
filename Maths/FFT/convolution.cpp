/*
Convolution(A,B) gives us C of size(n+m)
where 
Ci=∑AjBi-j
i.e C0=A0*B0
    C1=A1*B0+A0*B1
    C2=A2*B0+A1*B1+A0*B2
    and so on...

if A[] represents a n degree poltnomial with coefecients a0+a1x+a2x^2+....
and simillarly B[] represents a m degree poltnomial with coefecients b0+b1x+b2x^2+....
than C[] represents coeffeceint of A*B(multiplication of polynomials).

*/


//how to get convolution
// use the template_with_atcoder.cpp code

//you can also use convolution_ll for using on long long
vector<long long> c = convolution(a, b);
vector<long long> c = convolution<998244353>(a, b); // to get values under mod 998244353