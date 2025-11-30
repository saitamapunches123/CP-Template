struct Dynamic_Merge_Sort_Tree{
  int n;
  vector<multiset<int>> st;//static so using a vector
  Dynamic_Merge_Sort_Tree(vector<int>& a){
    n=a.size();
    st.assign(4*n,{});
    build(1,0,n-1,a);
  }
  void build(int node,int ss,int se,vector<int> &a){
    if(ss==se){
      st[node]={a[ss]};
      return;
    }
    int m=(ss+se)/2;
    build(2*node,ss,m,a);
    build(2*node+1,m+1,se,a);
    for(int i=ss;i<=se;i++)
      st[node].insert(a[i]);
  }
  void update(int node,int ss,int se,int i,int ov,int nv){
    if(i<ss or i>se)
      return;
    int m=(ss+se)/2;
    update(2*node,ss,m,i,ov,nv);
    update(2*node+1,m+1,se,i,ov,nv);
    auto it=st[node].find(ov);
    if(it!=st[node].end())
      st[node].erase(it);
    st[node].insert(nv);
  }
  int query(int node,int ss,int se,int l,int r,int x){// get lower_bound of x in range l to r
    if(l>se or r<ss)
        return INT_MAX;
    if(l<=ss and r>=se){
      auto it=st[node].lower_bound(x);
      if(it==st[node].end())
        return INT_MAX;
      return *it;
    }
    int m=(ss+se)/2;
    return min(query(2*node,ss,m,l,r,x),query(2*node+1,m+1,se,l,r,x));
  }
  int query(int l,int r,int x){
    return query(1,0,n-1,l,r,x);
  }
};