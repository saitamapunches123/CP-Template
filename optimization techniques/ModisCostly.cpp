/*
  Try to reduce mod operations as much as possible.

  This sumbisson TLEs:
  https://cses.fi/problemset/result/18116285/
  This gave AC:
  https://cses.fi/problemset/result/18116291/

  Difference:
*/

int sum=0;
for(int i=0;i<n;i++)
  sum=(sum+dp[i])%mod; // TLE


ll sum=0;
for(int i=0;i<n;i++)
  sum+=dp[i];
sum%=mod; // AC