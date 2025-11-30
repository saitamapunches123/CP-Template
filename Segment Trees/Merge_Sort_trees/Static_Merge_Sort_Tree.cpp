struct Static_Merge_Sort_Tree{
  int n;
  vector<vector<int>> st;//static so using a vector
  Static_Merge_Sort_Tree(vector<int>& a){
    n=a.size();
    st.assign(4*n,{});
    build(1,0,n-1,a);
  }
  void combine(int node){
    int l=2*node,r=2*node+1;
    int ls=st[l].size(),rs=st[r].size(),i=0,j=0;
    int ts=ls+rs;
    st[node].assign(ts,0);
    for(int k=0;k<ts;k++){// use 2 pointers to combine left and right
      if(i<ls and (j==rs or st[l][i]<st[r][j])){
        st[node][k]=st[l][i];
        i++;
      }else{
        st[node][k]=st[r][j];
        j++;
      }
    }
  }
  void build(int node,int ss,int se,vector<int> &a){
    if(ss==se){
      st[node]={a[ss]};
      return;
    }
    int m=(ss+se)/2;
    build(2*node,ss,m,a);
    build(2*node+1,m+1,se,a);
    combine(node);
  }
  int query(int node,int ss,int se,int l,int r,int x){// get cnt of valus in subarray [l,r] that are >x
    if(l>se or r<ss)
        return 0;
    if(l<=ss and r>=se)
      return st[node].end()-upper_bound(st[node].begin(),st[node].end(),x);
    int m=(ss+se)/2;
    return query(2*node,ss,m,l,r,x)+query(2*node+1,m+1,se,l,r,x);
  }
  int query(int l,int r,int x){
    return query(1,0,n-1,l,r,x);
  }
};