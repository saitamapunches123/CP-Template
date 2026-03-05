// Cn=1/(n+1) 2nCn=2n!/(n+1)!*n!
int catlan(int n){ 
    ll num=facts[2*n];
    ll den=(inv_facts[n+1]*inv_facts[n])%mod;
    // cout<<n<<" "<<num<<endl;
    return (num*den)%mod;
}
/*
Applications of Catalan number:

1) Cn is equal to the number of valid parenthesis expressions of length 2n
2) Cn is equal to the number of full binary trees with n+1 leaves
3) Cn is equal to the number of mountain ranges of length 2n consisting of n
 upstrokes and n downstrokes. (Simmilar to valid parenthesis)
*/

Reference: https://usaco.guide/adv/catalan?lang=cpp