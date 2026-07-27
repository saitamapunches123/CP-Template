/*
  The same pattern of Matrix exponentation can be used with any ASSOCIATIVE OPERATION i.e.merge(a, merge(b, c)) == merge(merge(a, b), c).
*/
// https://cses.fi/problemset/task/1724
ll inf=(ll)1e18+1;
Matrix merge(Matrix &a,Matrix &b){
  int ra=a.size(),ca=a[0].size(),cb=b.size();
  Matrix ans=make2D(ra,cb,inf);
  for(int i=0;i<ra;i++){
    for(int j=0;j<cb;j++){
      for(int k=0;k<ca;k++){
        ans[i][j]=min(ans[i][j],a[i][k]+b[k][j]);
      }
    }
  }
  return ans;
}
Matrix explode(Matrix &base,int k){
  Matrix ans=base;
  while(k>0){
    if(k&1)
      ans=merge(ans,base);
    base=merge(base,base);
    k>>=1;
  }
  return ans;
}
void solve(int tc) {
  int n,m,k;cin>>n>>m>>k;
  Matrix mat=make2D(n,n,inf);
  for(int i=0;i<m;i++){
    int u,v,w;cin>>u>>v>>w;
    u--;v--;
    mat[u][v]=min(mat[u][v],w);
  }
  // display(mat);
  Matrix ans=explode(mat,k-1);
  // display(ans);
  ll res=(ans[0][n-1]==inf?-1:ans[0][n-1]);
  cout<<res<<endl;
}