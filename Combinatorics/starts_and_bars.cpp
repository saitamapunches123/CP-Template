/*
usefull for when dealing with k identical items (i.e you for example you have 3 apples 2 oranges 5 bananas and you want to choose 4 of them)

Theorem¶
The number of ways to put n identical objects into k labeled boxes is n+k-1 C n

HOW TO IDENTIFY STAR AND BARS PROBLEM???
whenever exprsions if of the form 

n=4 and k=3

**|*|* => number of arrangements =n+k-1Ck-1

x1+x2+x3+...xk=n
where x1,x2,x3....>=0 
i.e xi represents the number of items in box i
or can be represented as stars and bars 
thus number of solutions of the above equation is
n+k-1 C n = n+k-1 C k-1


HOW TO DEAL WITH LOWER BOUNDS???
let x1+x2+x3+....+xk=n and xi>=ai
so, x1-a1+x2-a2+...+xk-ak=n-a1-a2-...ak
thus number of solutions of the above equation is
n-a1-a2-...ak+k-1 C k-1


HOW TO DEAL WITH UPPER BOUNDS???
using inclusion exclusion principle
convert upper bound to lower bound
thus for xi<ai
ans= toal- solution with xi>=ai = n+k-1 C k-1 - (n-ai+k-1 C k-1) 
*/


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
    /*
    usefull to find the number of ways to distribute n identical items in k boxes
    OR
    number of solution to x1+x2+...xk=n for xi>=0
    ans=n+k-1 C n=n+k-1 C k-1
    */
    ll stars_and_bars(ll items,ll boxes){
      return nCr(items+boxes-1,items);
    }
};