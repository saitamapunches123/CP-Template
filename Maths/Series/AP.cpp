ll nthterm(ll a,ll d,ll n){
    return a+(n-1)*d;
}
ll sumAP(ll a,ll d,ll n){
  ll an=nthterm(a,d,n);
  return n*(a+an)/2;
}


ll nthtermMod(ll a,ll d,ll n){
  return (a+(n-1)*d)%mod;
}

int inv2 = mod_inv_fermat(2,mod);
ll sumAPMod(ll a,ll d,ll n){
  a%=mod;d%=mod;n%=mod;	
  ll an=nthtermMod(a,d,n);
  ll ans=(n*(a+an))%mod;
  return (ans*inv2)%mod;
}