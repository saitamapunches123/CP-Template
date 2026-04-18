/*
 Useful when dealing with counting distinct objects under group actions
 OR in simple terms:
 Count unique configurations where symmetric ones are considered the same.

 Example:
 Cyclic strings → ABC, BCA, CAB are considered identical

 ------------------------------------------------------------

 Burnside’s Lemma:


 Number of distinct configurations =

        (1 / n) * Σ [ Fix(k) ]   for k in [1,n]

 where:
 - n =  number of symmetries For cyclic strings, n = size of string as n rotations are possible
 - Fix(k) = number of configurations unchanged (fixed) by transformation k OR 
  Number of combinations Such that:
  before kth transformation and after kth transformation the configuration is same.

 ------------------------------------------------------------

 In words:
 → For each symmetry, count how many configurations remain unchanged
 → Take the average over all symmetries

 ------------------------------------------------------------
*/

/*
  https://cses.fi/problemset/task/2209
  Counting Necklaces
  here number os symetris =n we can rotate the necklace n times
  C(k)=m^gcd(k,n) as for C(k) ai=a(i+k)%mod n so we can only choose the firs k values and k must devide n also
*/
int ans=0;
for(int k=0;k<n;k++){
  int s=gcd(k,n);
  ans=(ans+pow_m[s])%mod;
}
ans=(ans*mod_inv_fermat(n,mod))%mod;
cout<<ans<<endl;

https://cses.fi/problemset/task/2210