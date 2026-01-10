int inv2 = mod_inv_fermat(2,mod);
ll sumLRMod(ll l,ll r){ // sum of l,l+1,....r
  ll sz=(r-l+1)%mod;
  int sum=(l+r)%mod;
  int ans=(sz*sum)%mod;
  return (ans*inv2)%mod;
}
/*
  gets  Σi=1,..n n%i in sqrt(n)
  as n%i = n - i*floor(n/i) 
  Σi=1,..n n%i = n*n - Σi*floor(n/i)
  number of distinct values of floor(n/i) = sqrt(n)
*/
int sum_n_mod_i(int n){
  int ans=n%mod;
  ans=ans*ans;
  int l=1;
  while(l<=n){
    int val = n/l; // value of floor(n/i)
    int r = n/val; // at r+1 val change
    int rem = (val*sumLRMod(l,r))%mod;
    ans=(ans+mod-rem)%mod;
    l=r+1;
  }
  return ans;
}