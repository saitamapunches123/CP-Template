/*
CRT or Chineese Remainder theorem is used
where 
X=a1 (mod m1) 
X=a2 (mod m2)
X=a3 (mod m3)
and we need to combine these to find

X=? (mod m1*m2*m3)

if all mod (mi,mj) are pair wise co prime.

let M=m1*m2*m3.....
and Mi=M/mi
and yi=Mi^-1(mod mi)

X=(Summation ai*Mi*yi) mod M
*/


//FOR EXAMPLE USING CRT TO COMBINE LUCASS ANSWER FOR mod=10
long long nCr(long long n,long long r){
    long long x1=nCrprime(n,r,2);
    long long x2=nCrprime(n,r,5);
    int inv2=3; // as 2*3=6=1(mod 5)
    int inv5=1; // as 5*1=5=1(mod 2)
    long long ans=(x1*inv5*5+x2*inv2*2)%10;
    return ans;
}