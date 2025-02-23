/*
PASCALS TRIANGLE
(Gives Binary coeefecients)
        1
       1 1
      1 2 1
     1 3 3 1
    1 4 6 4 1
   
pascal[r][c]=pascal[r-1][c-1]+pascal[r-1][c] n^2
to get 1 row of Pascals Triange we can use nCr
as pascal[r]= rC0,rC1,rC2,..rCi,.....
*/

vector<ll> get_pascal(int row,ll mod){
    vector<ll> ans(row+1);
    for(int i=0;i<=row;i++){
        ans[i] =nCr(row,i,mod);
    }
    return ans;
}

/*
HOW TO CALCUALATE nCr under a mod
If can calculate mod_inv fact[r]*fact[n-r] than fine
else use

LUCAS THEOREM to calculate nCr under a mod(p) p is prime
LET n=summation ni*p^(k-i) 
and r=summation ri*p^(k-i) 
THAT is find the representaion of n and r under p
Than nCr(mod p)=product niCri (mod p) here if ri>ni niCri=0

We can use this if p is prime 
else find prime factorization of p and Use CRT To combine
*/

ll nCrprime(ll n,ll r,ll p){
    vector<ll> facts(p+1);
    facts[0]=1;
    for(int i=1;i<=p;i++)
        facts[i]=i*(facts[i-1]);
    ll ans=1;
    while(n>0){
        int ni=n%p,ri=r%p; //represetation of n and r in p
        if(ri>ni) return 0;
        ans=(ans*(facts[ni]/(facts[ri]*facts[ni-ri])))%p;
        n=n/p;
        r=r/p;
    }
    return ans;
}