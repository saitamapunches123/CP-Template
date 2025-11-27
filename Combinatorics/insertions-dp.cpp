/*
Usefull when we need to find the alid rearangements of an array/string.
For example:https://www.codechef.com/problems/P6BAR or https://atcoder.jp/contests/abc431/tasks/abc431_f

The idea is to think of the problem as a insertion problem.
The order of inserting element depends on the question
Here for the questions need to insert in sorted order

{} first we insert the first element(only 1 place to) insert it
{x} than the second element can be inserted in 2 places check which of these places is valid
{x,y} than the third element can be inserted in 3 places check which of these places is valid
and so on....

insert all the elements and than return the number of valid ways to insert them
*/

// FOR: https://www.codechef.com/problems/P6BAR
ll mod=1e9+7;
vector<vector<ll>> dp;
// here inserting from 0 to n-1
ll recur(int i,int k,int n){
  if(i==n)
    return k==0;
  if(dp[i][k]!=-1)
    return dp[i][k];
  ll not_mex_choice=i-1;// number of place to insert the ith element that wont result it in being a mex
  not_mex_choice=(not_mex_choice*recur(i+1,k,n))%mod;
  ll mex_choice=0;
  if(k>=1)
    mex_choice=(2ll*recur(i+1,k-1,n))%mod;//number of place to insert the ith element that will result it in being a mex
  return dp[i][k]=(mex_choice+not_mex_choice)%mod;
}