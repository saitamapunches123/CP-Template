/*
Lets say you have k values you can only pick these k values even number of times
i.e you can pick them up 0 times 2 times 4 times and so far
so number of ways=> kC0+kC2+kC4+kC6+....
NOW,
From binary expansion:

(a+b)^k=kC0*b^k+kC1*a*b^k-1+kC2*a^2*b^k-2....
so, 2^k=kC0+kC1+kC2+kC3+....
ans if a=-1 and b=1
    0=kC0-kC1+kC2-kC3...
By adding and subtracting these equations we get

kC0+kC2+kC4+....=2^(k-1)
kC1+kC3+kC5+....=2^(k-1)
*/
ll number_of_ways(ll k,vector<ll> &pow_2){
    return pow_2[k-1];
}