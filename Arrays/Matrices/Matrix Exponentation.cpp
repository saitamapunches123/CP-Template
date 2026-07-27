int mod= 1000000007;
using vi=vector<ll>;
using Matrix = vector<vi>;
void display(Matrix &A){
    cout<<endl;
    for(auto x:A){
        display(x);
    }
    cout<<endl;
}
Matrix multiply(Matrix& A, Matrix& B) {
    int ra = A.size(), ca = A[0].size(),rb=B.size() cb = B[0].size();
    // ca must be equal to rb
    Matrix C(ra, vi(cb, 0));

    for (int i = 0; i < ra; i++) {
        for (int j = 0; j < cb; j++) {
            __int128 sum = 0;
            for (int k = 0; k < ca; k++) 
                sum += 1LL * A[i][k] * B[k][j];
            C[i][j] = sum % mod;
        }
    }
    return C;
}

Matrix get_identity(int n){
  Matrix ans(n,vi(n,0));
  for(int i=0;i<n;i++)
    ans[i][i]=1;
  return ans;
}
Matrix matrix_exponentation(Matrix base, int exp) {
  int n = base.size();
  Matrix ans = get_identity(n);
  while (exp) {
      if (exp & 1)
          ans = multiply(ans, base);
      // cout<<exp<<endl;
      // display(base);
      base = multiply(base, base);
      exp >>= 1;
  }
  return ans;
}


int n,m,k;cin>>n>>m>>k;
if(n==1){
  cout<<m<<endl;
  return;
}
Matrix base(m,vi(m,1)); 
for(int i=0;i<k;i++){
  string invalid;cin>>invalid;
  int x=get_code(invalid[0]),y=get_code(invalid[1]);
  base[x][y]=0;
}
// display(base);
Matrix ans=matrix_exponentation(base,n-1);
// display(ans);
int sum=0;
for(auto x:ans){
  for(auto y:x)
    sum=(sum+y)%mod;
}
cout<<sum<<endl;
/*
    Let dp[len][i][j] denote the number of valid strings/paths of length `len`
    that start from state `i` and end at state `j`.

    Define `base[i][j] = 1` if we can directly transition from state `i` to
    state `j`, otherwise 0.

    Observe that a string/path of length `k` consists of exactly `k - 1`
    transitions between states.

    Therefore:
        Length = 2  -> 1 transition -> base
        Length = 3  -> 2 transitions -> base²
        Length = 4  -> 3 transitions -> base³
        ...
        Length = n  -> (n - 1) transitions -> base^(n - 1)

    Matrix multiplication naturally counts all possible intermediate states.
    For example,

        (base²)[i][j] = Σ base[i][k] * base[k][j]

    which is precisely the number of ways to go from state `i` to state `j`
    using two transitions (i -> k -> j).

    In general, base^k counts the number of ways to perform exactly `k`
    transitions between states.

    Since a length `n` sequence contains `n - 1` transitions,

        dp[n] = base^(n - 1)

    Hence, we can compute dp[n] efficiently using matrix exponentiation.
*/
// https://codeforces.com/contest/222/problem/E
// https://leetcode.com/problems/number-of-zigzag-arrays-ii/submissions/1784967847/?envType=daily-question&envId=2026-06-24