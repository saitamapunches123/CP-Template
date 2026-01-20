int mod=1e9+7;
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
vector<int>spf;
void build_spf(int n){ //SIMILLAR TO SIEVE but here spf[i] is the smallest prime factor of i
  spf.assign(n+1,0);
  for(int i=1;i<=n;i++)
    spf[i]=i;
  for(int i=2;i*i<=n;i++){
    if(spf[i]==i){//i is prime
      for(int j=i*i;j<=n;j+=i){
        if(spf[j]==j)
          spf[j]=i;
      }
    }
  }
}
map<int,int> prime_factorize(int x){
  map<int,int> ans; // if we want distinct primes else use vector
  while(x>1){
    ans[spf[x]]++;
    x=x/spf[x];
  }
  return ans;
}


// lcm of(a1,a2,a3...an) => p1^mx1*p2^mx2*p3^mx3 -> mx1 => max times p1 prime factor comes in any of the ai's.
int lcm_array_mod(vector<int> &arr){
  map<int,int> max_freq;
  for(auto x:arr){
    map<int,int> facts=prime_factorize(x);
    for(auto [x,f]:facts)
      max_freq[x]=max(max_freq[x],f);
  }
  int lcm=1;
  for(auto [x,f]:max_freq)
    lcm=(lcm*mod_exp(x,f,mod))%mod;
  return lcm;
}


/* 
  PS: using pairwise gcd and finding lcm(a1,a2,a3)=> lcm(lcm(a1,a2),a3) under mod will not work as lcm(x,y)=x*y/gcd(x,y) but if x lcm till now is kept in mod gcd(x,y) will not work
*/