ll kadanes(vector<ll> &nums){
   ll ans=LLONG_MIN,cans=0;
   for(auto x:nums){
      cans+=x;
      ans=max(ans,cans);
      cans=max(cans,0ll);
   }
   return ans;
}