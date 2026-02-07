/*
In subsequence dp for each element we can either pick or not pick it
so
 from dp[i] we can go to dp[i+1] by either picking a[i] or skipping a[i].
but in Subarray dp:
  if we skip a[i] we can not pick any element after a[i] Subarray will break.
  Thus for each a[i]
  -> we can either pick the element.
  -> or end our subarray.
*/

// so now dp[i] -> the max/min for all the subarray starting at i
// so final answer will be max/min(dp[i])

ll recur(int i,int state){
  ll ans=(state==2?0:-inf);
  if(i==n or a[i]==a[i-1])
      return ans;
  if(dp[i][state]!=-1)
      return dp[i][state];
  int nstate=state;
  if(state==0 and a[i]<a[i-1])
      nstate=1;
  else if(state==1 and a[i]>a[i-1])
      nstate=2;
  else if(state==2 and a[i]<a[i-1])
      return dp[i][state]=ans;
  ans=max(ans,recur(i+1,nstate)+a[i]); //either pick the element or end the subarray
  return dp[i][state]=ans;
}
long long maxSumTrionic(vector<int>& nums) {
  a=nums;
  n=a.size();
  ll ans=-inf;
  memset(dp,-1,sizeof(dp));
  for(int i=1;i<n;i++){ 
      if(a[i]>a[i-1])
          ans=max(ans,recur(i,0)+a[i-1]);
  }
  return ans;
}



-> https://leetcode.com/contest/weekly-contest-487/problems/longest-alternating-subarray-after-removing-at-most-one-element/description/
-> https://leetcode.com/problems/trionic-array-ii/description/