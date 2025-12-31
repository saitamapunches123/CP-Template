/*
HOW TO SOLVE?
  
  ax=b mod m

STEP1) let d=gcd(a,m)
ax=b mod m we can devide whole equation by d
(a/d)x=(b/d) mod (m/d)

THE EQUATION CAN HAVE

1) NO SOLUTION (if d doesnt divide b) b != 0 (mod d)
2) SOLUTIONS

NOW let a`=a/d and b`=b/d and m`=m/d
now gcd(a`,m`)=1 so we can find the inverse of a` under mod m`
and 

x=(b`*inv(a`)) mod m`
*/

pair<ll,ll> extend_euclid(ll a, ll b) {  // returns {x,y} such that ax+by=gcd(a,b)
  if (b == 0) { return {1, 0}; }
  auto [x,y] = extend_euclid(b, a % b);
  return {y, x - a / b * y};
}
//modular inverse of a under mod given that gcd(a,mod)=1
ll mod_inv(ll a, ll mod) {
  auto [x,y] = extend_euclid(a, mod); // x*a + y*mod = gcd(a,mod)=1 
  return x % mod; // x*a ≡ 1 mod m
}

// solves ax=b mod m 
pair<ll,ll> solve_linear_equation_under_mod(ll a, ll b, ll m) {
    m = abs(m);
    a = ((a % m) + m) % m;
    b = ((b % m) + m) % m;

    ll g = gcd(a, m);
    if (b % g != 0) return {-1, -1}; // no solution

    // reduce by gcd as ax=b mod m => (a/g)x=(b/g) mod (m/g)
    a /= g;
    b /= g;
    m /= g;

    ll a_inv = mod_inv(a, m); // inverse of a mod m
    ll ans = (a_inv * b) % m;

    return {ans, m}; // x = ans (mod m) PS ans is now under m/g and  not m passed
}