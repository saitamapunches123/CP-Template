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
// also gets mod_inv in log(n)

/*
To get 17 mod 43
43 =17*2+9
17=9*1+8
9=8*1+1
8=1*8+0

gcd =1 inverse exists
1=9-8*1
1=9-(17-9*1)*1=9*2-17*1
1=(43-17*2)*2-17*1=43*2-17*5
1=43*2-17*5
1=-5*17 (mod 43)
17 inv = -5 mod 43 =38 mod 43
*/