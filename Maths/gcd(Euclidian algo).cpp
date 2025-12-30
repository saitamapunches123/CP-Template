// Euclidian algo to find gcd of 2 numbers in log(min(a,b)) time
ll gcd_euclid(ll a,ll b){
  if(b==0)
    return a;
  return gcd_euclid(b,a%b);
}

/*
To get gcd of 45 and 20
45=20*2+5
20=5*4+0
gcd=5 (last non zero remainder)
*/