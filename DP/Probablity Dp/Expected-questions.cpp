// https://codeforces.com/contest/1753/problem/C

/*
here there is infinity case

dp[x]=1+p*dp[x-1]+(1-p)*dp[x] //so cant use recursion
dp[x](p)=1+p*dp[x-1]
dp[x]=1/p+dp[x-1]

*/
pair<ll,ll> ans={0,1};
ll num=(n*(n-1)/2)%mod;
for(ll i=1;i<=ones_in_zeros;i++){
  ll den=(i*i)%mod;
  pair<ll,ll> add={num,den};
  // cout<<add.first<<" "<<add.second<<endl;
  ans=add_fracts(ans,add);
}
cout<<get_fract_inv(ans)<<endl;
