/*
spf -> smallest prime factor i.e spf[10]= 2
we can compute spf of 1 to n in O(nloglogn) time. Simillar to sieve

Benefits of spf:
We can factorize a number in O(logn) time
*/
vector<int> build_spf(int n){ //SIMILLAR TO SIEVE but here spf[i] is the smallest prime factor of i
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
  return spf;
}

vector<int> prime_factorize(int x){
  set<int> ans; // if we want distinct primes else use vector
  while(x>1){
    ans.insert(spf[x]);
    x=x/spf[x];
  }
  return vector<int>(ans.begin(),ans.end());
}